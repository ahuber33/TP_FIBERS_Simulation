# TPSim for Thomson Parabola Simulation WITH FIBERS [huber@cenbg.in2p3.fr, huberarnaud@gmail.com]

# INSTRUCTIONS TO USE THE SIMULATION
#- Download the VMWare Geant4.11.0.1 from https://heberge.lp2ib.in2p3.fr/G4VM/index.html
#- Copy all the files from TP_Simulation folder (https://github.com/ahuber33/TP_Simulation)
#- Create a build folder in the TP_Simulation folder and go inside.
#- Use this command : "cmake -DGeant4_DIR=$G4COMP ../" and compile it with make
#- The executable TPSim will be add to your bin folder
#- If you want to have a visualization, launch this command : "./TPSim [name of ROOT file ]". It will generate 1 particle according to the vis.mac with QT and you will have a ROOT file with the name you gave in response located in the Resultats folder.
#- If you want to have statistics without the visualization, use this command : "./TPSim [name of ROOT file] [number of events generated] [name of macro]". Personnaly, I used the vrml.mac but you can create another one. Just to remember that you need to write the name of your macro when you launch the simulation.
#- An TPSim.cfg file is located in bin directory. All the dimensions necessary are in this file to avoid recompilation when you want to change some parameters. If you add some other dimensions, don't forget to add the variables in Geometry.cc.
#- Based on G4EmStandardPhysics_option3 with additional Optical part.
#- DO NOT HESITATE TO REPORT BUGS OR ANY IDEAS THAT WILL IMPROVE THE SIMULATION !!!!

#######################################################################
################## ANCIENS COMMIT FROM TP SIM #########################
#######################################################################

# Commit #14 le 17/06/2022 [TPSim.0.6.0]
#- Ajout des fonctions de paramétrisation permettant de répliquer une fibre en un certain nombre afin de gagner du temps de calcul et de génération de géométrie. Egalement un souci de simplification du code nécessaire car impossible de générer 1000 fibres différentes => Ajout des fichiers FiberParametrisation.hh et .cc
#- Définition d'un nouveau matériau (FP) correspondant au cladding externe d'une fibre circulaire multi cladding
#- Ensemble des paramètres liés aux fibres a été parametrisé (longueur, épaisseur, espacement, multi cladding ou non, type de géométrie) et automatisé. Pour passer d'une géométrie à l'autre, il suffit de changer les paramètres dans le TPSim.cfg.
#- Ajout des fonctions permettant d'accéder aux informations liées à la fibre dans TPSim.cfg
#- Ajout d'une variable Angle afin de pouvoir vérifier la bonne propagation des photons dans la fibre. EN ATTENTE !!!!

# Commit #15 le 01/09/2022 [TPSim.0.7.0]
#- Définition de l'angle des photons dans la fibre de cette façon : angle = acos((z-zpre)/aStep->GetStepLength())
#- Ajout du modèle G4FastSimulationManagerProcess afin de pouvoir accélerer la simulation. Lorsqu'un photon effectue 3 réflexions totales, son chemin est pris en compte et translater directement vers la fin de la fibre afin de gagner du temps de calcul.
#- De nombreuses vérifications ont été effectués afin de comprendre ce qui se passait au sein de la fibre simple caldding ronde pour l'instant. Le modèle est principalement utilisable pour les photons dont les angles sont ceux permettant aux photons de se propager dans le coeur de la fibre. Il est néanmoins possible, au delà d'une certaine longueur de fibre et en négligeant le cross-talk, d'arrêter de suivre les angles supérieures afin de gagner beaucoup de temps de calcul !!!
#- Ajout de fichiers FastSimModelOpFiber & SimG4FastSimOpFiberRegion. Un Holder est crée et défini en tant que région où s'applique le modèle (trigger, doIt, autres calculs).
#- Ajout des informations dans le fichier ROOT concernant l'angle de départ et de détection des photons ainsi que l'ensemble des points X, Y et Z de la trajectoire d'un photon afin de pouvoir reconstruire les trajectoires par la suite. Ajout également d'une information dans le fichier ROOT concernant le statut final du photon (escaped, trasmitted, detected, asborbed, ...).
#- Création d'un code d'analyse (PhotonTrajectory) permettant de visualiser les trajectoires des photons dans la fibre ronde simple cladding. Sélection possible en fonction de l'angle et du statut final du photon
#- Ajout sans utilisation du PMMA Optical Surface
#- Ajout des informations Time, polarisation et modifications sur les px,y,z -> PreStep plutot que PostStep
#- Ajout de la possibilité d'accéder aux informations sur la normal à une surface sur laquelle arrive un photon dans le SteppingAction. Sert pour potentiellement du débug.
#- Ajout des accès aux potentiels différents types de réfraction, réflexions dans le SteppingAction

# Commit #16 le 08/09/2022 [TPSim.0.7.1]
#- Ajout de la variable DetectorTranslation dans TPSim.cfg afin de pouvoir dans le futur décaler la zone de détection par rapport aux fibres (étude de l'éloignement de la lentille)
#- Ajout du paramètre sur le multicladding dans la fonction d'appel du module G4Fast. Cela permettra de mieux utiliser les coupures sur les angles qui se propagent dans les différents types de fibres
#- Correction du bug de placement des fibres dans le FiberHolder. En effet, l'espace entre les fibres n'était pas pris en compte, ce qui lors de la génération d'un grand nombre de fibres entrainait des recouvrements et donc des soucis au niveau de la simulation. Ce problème est dorénavant patché de façon certaine pour la géométrie ronde single cladding. Le même processus a été réalisée pour la géométrie ronde multicladding auquel il reste de nombreuses vérifications à effectuer
#- Tests en cours pour déterminer pourquoi des photons qui partent vers l'arrière et qui devraient logiquement sortir de la fibre sont de retour et vont jusqu'à être détectés

# Commit #17 08/09/2022 [TPSim.0.7.2]
#- Explication des photons détectés partant à la base dans le sens opposé. Bien que la majorité des photons ayant ces angles sont transmis à travers cette interface, en fonction de l'angle et de la polarisation du photon, il y a une probabilité non nul pour que le photon soit réflechi selon ce qu'on appelle une réflexion de Fresnel (voir image correspondante pour plus de détails). Il est donc normal de voir ces angles pouvoir potentiellement se propager et aller jusqu'au détecteur, ce n'est pas une erreur dans la simulation !!!!
#- Exemple d'un de ces photons présent ici : bin/Event_detected_angle161.deg

# Commit #18 le 25/10/2022 [TPSim.0.8.0]
# - Abandon de la méthode de génération du bunch de fibres avec l'outil G4VPVParameterisation de GEANT4. En effet, celui-ci introduit un dysfonctionnement dans le suivi des photons optiques dans la chambre du à une erreur lors de la prise en compte de la normale à la surface de la fibre. Celle-ci est inversée ce qui fait qu'un photon étant à la base piégé dans la fibre peut se retrouver en dehors de celle-ci...
# - Remplacement de la méthode précédente par une boucle for permettant de générer l'ensemble des fibres à partir du nombre indiqué dans le fichier de config.
# - Nécessaire de changer la génération des volumes solides dans le fichier Geometry.cc. Précédemment, les volumes circulaires des fibres étaient plein afin de pouvoir être le holder du volume ayant un diamètre plus petit. Doréanavant, vu que chaque élément est distinct de l'autre et défini dans le FibersHolder, il est nécessaire de créer les vraies volumes (donc sous la forme d'anneau).
# - Création de tableaux de G4VPhysicalVolume pour prendre en compte l'ensemble des modifications précédentes et afficher le bunch de fibres. Méthode OK !!!
# - Passage de l'efficacité quantique du détecteur à 1 afin que les photons détectés correspondent aux photons transmis jusqu'au détecteur (plus facile pour les études préliminaires).
# - Ajout d'un paramètre dans l'outil G4FAST permettant de calculer la longueur de la trace à partir du moment où elle effectue a première réflexion totale et non pas de puis sa création.
# - Ajout d'un paramètre dans l'outil G4FAST permettant d'effectuer certaines opérations ou non si la géométrie des fibres est circulaire ou carrée (exemple du suivi des photons à grand angle dans la géométrie carrée où le module G4FAST est désactivée).
# - Ajout d'un paramètre Air_Index dans le fichier de config Materials.cfg afin de pouvoir changer l'indice de l'air autour des fibres sans recompiler le code.
# - Ajout d'un paramètre dans le EventAction permettant de récupérer l'indice optique de l'air autour des fibres dans le SteppingAction afin de pouvoir l'utiliser dans le module d'accélération.
# - Ajout du paramètre G4FAST dans le fichier de configuration. Ce dernier permet d'activer ou non le module d'accélération du suivi des photons sans recompiler le code comme précédemment.
# - Ajout de ligne permettant d'accéder au CopyNumber si nécessaire par la suite (Plus nécessaire actuellement car nous avons arrêté la génération des fibres avec l'outil de paramétrisation)
# - MAJ des corrections sur la longueur d'atténuation à considérer en fonction de la géométrie qui est testée pour reproduire les datas sans le module d'accélération.
# - Création de dossiers pour les différents fichiers ROOT afin de classifier les différentes études
# - VERSION DE CODE UTILISEE POUR GENERER LE FICHIER EXCEL LABS_TPSIM AFIN DE VERIFIER LA CONCORDANCE ENTRE LA SIMU OPTIQUE COMPLETE ET L OUTIL G4FAST. TOUT EST OK !!!!!

# Commit #19 le 02/11/2022 [TPSim.0.8.1]
# - IMPORTANT : Version de la simulation ayant permis d'estimer les résultats d'un bunch de fibres arrivant directement sur la caméra ORCA.
# - Changement dans la configuration de la simulation pour créer des fibres plus petites (0.2mm) avec un espacement plus faible entre (0.05mm) afin de simuler le bunch de fibres directement sur la camera
# - Nettoyage des dossiers du code en enlevant le fichier de geometrie du Dolphy Beta (Carmelec) ainsi que les fichiers GDML associés.
# - Ajout dans le code de la possibilité d'ajouter une lentille dans la simulation afin de pouvoir les ramener sur la caméra. Commenté pour le moment car pas utilisé. A CONFIRMER PAR LA SUITE !!!! VERIFICATIONS NECESSAIRES
# - Ajout des fichiers GDML correspondant à des lentilles issues de ThorLabs
# - Ajout des fichiers de config pour la fibres (matériau N-BK7, indice optiqque et longueur d'absorption)
# - Ajout des variables et fonctions permettant (dans le cas de l'utilisation des lentilles) d'accéder à la position des photons au niveau de la sortie des fibres, au niveau de la lentille et au niveau du détecteur.
# - Creation d'un fichier Plot_2D_cross_talk.cc permettant de tracer l'évolution du cross-talk en focntion du nombre de fibres et de la longueur de ces dernières.
# - Réarrangement des fonctions dans le fichier FastSimModelOpFiber.cc
# - Création d'un fichier de géomérie backup
# - Fonctions permettant de récupérer les trajectoires pour les plotter par la suite ont été commentées pour ne pas créer de fuite mémoire lors de tirs à hautes énergies


#######################################################################
############# NOUVEAUX COMMITS FROM TP fibers SIM #####################
#######################################################################

# Commit #1 avec VERSION INITIAL DU CODE PROVENANT DE LA VERSION TPSim.0.8.1 [TPFIBERSSim.0.0.0]
# Les informations concernant principalement la fibre sont référencés au début de ce README. Si besoin d'informations supplémentaires, se reporter au README de TP_simulation !!!!
