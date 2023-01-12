# TPSim for Thomson Parabola Simulation [huber@cenbg.in2p3.fr, huberarnaud@gmail.com]

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

# Commit #1 le 23/02/2022 [TPSim.0.0.0]:
#-Reprise en main du code GMSim de la version G4-9.6p02 pour le mettre sur la version G4-11.0
#-Changement de l'intégralité des noms GMSim en TPSim
#-Premier nettoyage rapide du code sur certaines fonctions
#-Création Tree electrons + fonctions en vue de vérifier les PhysicsList

# Commit #2 le 24/02/2022 (Validation G4EM-electrons) [TPSim.0.1.0]:
#-Changement de la définition du Scintillateur pour coller aux données de ESTAR
#-Création matériau Carbon pour tests avec ESTAR
#-Géométrie basique pour le moment pour tests G4EM
#-Ajout d'un Script bash permettant de lancer plusieurs simulations tout en controlant le nombre de process => Script.sh qui utilise le vrml_base.mac pour créer des macro base_{i}.mac qui seront utilisés pour lancer la simulation
#-Mise au point d'un code d'analyse Plot.C et Plot.hh afin de comparer les CSDA des électrons dans plusieurs matériaux (Lecture fichier txt, lecture Tree, création TGraph)
#-Nettoyage du dossier bin (Scripts, macros et fichiers txt correspondants à la simulation GMSim)
#-De nombreux tests avec .gitignore pour faciliter l'utilisation

# Commit #3 le 25/02/2022 (Validation G4EM-protons) [TPSim.0.1.1]
#-Changement taille scintillateur pour pouvoir suivre le proton de 500 MeV sur toute sa trajectoire dans le Scintillateur
#-Changement définition holder de Orb en Box
#-Ajout d'un StopandKill pour gagner du temps sur les particules secondaires générées
#-Ajout des données de pstar pour comparaison avec simulation
#-Ajout d'un script (Script_rapide) permettant de lancer la même simulation sur plusieurs coeurs utilisant la même macro
#-Changement de valeur du Cut dans la PhysicsList (passage de 1mm à 1µm) afin de pouvoir suivre correctement le proton dans les différents matériaux
#-Le tree electrons est juste utilisé ici pour avoir les informations sur les protons -> Nécessité de faire attention par la suite et de surement créer un autre tree pour les protons
#-Du aux nombreux gammas crées, la condition de remplissage du tree (Estart=Edep) a été enlevé.

# Commit #4 le 28/02/2022 (Mise en place partie Optique) [TPSim.0.2.0]
#-Ajout des fichiers Coupling et PMT (temporairement ou non) afin de pouvoir vérifier la partie optique sur les scintillateurs SuperNEMO
#- Ajout de l'ensemble des fonctions, géométries, matériaux et variables liés à SuperNEMO (temporaire ou non) nécessaire pour la vérification de la partie optique
#- Ajout propriétés optique du scintillateur, mylar, teflon, colle, photocathode et PM
#- Lecture des fichiers config à base de vecteurs et plus de tableau (a nécessité la mise au point d'un petit code Reverse_file.C permettant de changer l'ordre de lecture du fichier. Précédemment de la plus petite à la plus grande longueur d'onde, maintenant c'est l'inverse d'où la présence des fichiers reverse).
#-Accès à l'ensemble des informations liéss à la scintillation et/ou Cerenkov puis transfert dans un Tree (pris en grande partie du code de SuperNEMO mais nettoyé et mis à jour).
#-Possibilité d'activer ou de désactiver la scintillation et/ou Cerenkov
#-Possibilité de considérer uniquement les photons détectés et/ou transmis
#-Changement du Cut dans la PhysicsList à 1mm pour faciliter/accélerer l'analyse optique avec électrons

# Commit #5 le 07/03/2022 (Ajout partie LaBr3 + nettoyage) [TPSim.0.3.0]
#- Ajout des fichiers géométries correspondant à la configuration HPD et PMT (fichiers de config inclus pour le scintillateur LaBr3 et le PM)
#- Ajout des spectres réels de flash X issues de l'expérience de Emmanuel au CELIA dans Geant4
#- Ajout de fonctions pour ploter les résultats dans Plot.hh
#- Création code LaBr3 attenuation pour vérification que Labs est bien pris en compte dans la simulation
#- Création code rapide permettant d'obtenir un étalonnage entre énergie et photons générés/détectés (etalonnage_LaBr3.C)
#- Remise en forme de l'ensemble des fichiers hh et cc avec l'indentation automatique
#- Ajout de commentaires sur certaines parties du code
#- Mise en forme du code plus propre avec déclarations des variables et fonctions en début de fichier pour faciliter la lecture
#- Ajout de la données "Time" dans le root de sortie permettant de connaitre la répartition temporelle des photons sur la photocathode

# Commit #6 le 09/03/2022 [TPSim.0.3.1]
#- Ajout de la propriété Rayleigh scattering et donc split de l'attenuation length en absorption length et scattering length selon [https://www.researchgate.net/publication/254060762_Optical_Absorption_Length_Scattering_Length_and_Refractive_Index_of_LaBr3Ce3]
#- Selon cette référence, l'absorption entraine quasi à chaque fois la réémission d'un photon derrière pour le LaBr3 donc à investiguer dans le futur !!!
#- Changement de position de certaines lignes de code pour plus de clarté

# Commit #7 le 16/03/2022 [TPSim0.4.0]
#- Ajout des longueurs de référence de la TP dans le fichier de config. L'ensemble des distances pour le placement des éléments dépend de ces paramètres. Ensemble des liens effectués
#- Ajout dans le vis.mac des lignes permettant d'afficher la direction des champs magnétiques et électriques
#- Création de l'ensemble des volumes principaux de la TP. La zone de champ magnétique est électrique est crée et englobe la partie créant le champ.
#- Ajout des fonctions permettant d'obtenir et de stocker les positions d'interaction des particules dans le détecteur.
#- Ajout des élements permettant de générer un champ magnétique et électrique uniforme dans le TPSimGeometry.cc. ATTENTION : La vérification des déviations pour le champ magnétique laissé apparaitre des écarts de plus en plus important entre la simu et les équations pour les trajectoires très déviées. A suivre et investiguer !!!!!!!!!! Ok pour le champ électrique !!!!
# - PROBLEME AVEC LA GENERATION DES IONS AVEC Z>2. NE PREND PAS EN COMPTE LA CHARGE IONIQUE DANS LE GPS/ION. INVESTIGATION EN COURS !!!!

# Commit #8 le 18/03/2022 [TPSim.0.4.1]
#- Ajout des propriétés du scintillateur ZnS et ajout dans la simulation
#- Création des variables associées au ZnS

# Commit #9 le 25/03/2022 [TPSim.0.5.0]
# - Problème du commit #7 avec la génération des ions avec Z>2 et une charge Q géré par la macro en partie réglé. Il est dorénavant possible de générer un noyau de Carbone avec une charge ionique allant de +1 à +6 pour le suivi dans la TP. Cela a été rendu possible avec l'ajout des G4BraggIonGasModel et G4BetheBlochIonGasModel permettant de suivre correctement les ions dans un milieu gazeux. Ainsi l'ion ne se retrouve pas automatiquement en équilibre avec le milieu dans lequel il se propage comme cela est le cas en règle générale dans GEANT4.
# - NEANMOINS, LA PRISE EN COMPTE DE CES FONCTIONS INDUIT UN BIAIS LORS DE L'INTERACTION DE CES IONS AVEC LE SCINTILLATEUR QUI ONT UN PARCOURS PLUS IMPORTANT CAR LE MODELE PRIS EST CELUI D'UN GAZ. EN COURS D'INVESTIGATION POUR RÉSOUDRE CE PROBLEME.
# - En attendant, le modèle AddIonGasModels() est désactivé et l'étude optique se portera uniquement sur des protons et alpha dans un premier temps. Néanmoins, pour juste suivre la déviation sans la production de photons, il est possible d'étudier ces ions en activant le modèle AddIonGasModels().
#- Simplification du code en regroupant l'ensemble des volumes crées dans un même fichier Geometry.cc. Les fichiers Scintillator.cc, PMT.cc, Coupling.cc et GdL.cc ont été effacés.
#- Simplification des Trees de résultats. Mise au point d'un Tree avec l'ensemble des résultats liés à l'optique (introduction des vecteurs pour l'accès aux informations liées aux photons détectés) et un Tree pour l'ensemble des informations issues de la TP.
#- Création des fonctions Set et Get pour chaque variable des Trees
#- Nettoyage des parties de code non nécessaires
#- Ajout des informations sur l'ID de la particule, son temps de vol (particule et photons) ainsi que sa charge.
#- L'ensemble des éléments de la géométrie bouge en fonction des paramètres de chacun des éléments de la configuration. Toutes les distances sont liées dans le TPSimGeometry.cc lors du placement des éléments.

# Commit #10 le 01/04/2022 [TPSim.0.5.1]
#-Quelques changements mineurs sur le code pour ne pas avoir des ficheirs de résultats trop gros (Branches non prises en compte et donc commentées)
#-Quelques petits bugs fixés.
#-Ajout des programmes d'analyse (Analyse_TP.cc et Analyse_TP.hh)

# Commit #11 le 24/04/2022 [TPSim.0.5.2]
#- Ajout des propriétés optiques du scintillateur NoWaSH de Liquido.
#- Ajout de l'efficacité quantique de la caméra CCD ORCA II
#- Code analyse ayant servi à la première étude projet RATP du 2 mai 2022 [Analyse_TP.cc & Analyse_Optique.cc]

# Commit #12 le 10/05/2022 [TPSim.0.5.3]
#- Ajout et prise en compte du fait que le ZnS est appliqué sur un guide de lumière ou sur un scintillateur. Création de la géometrie guide de lumière en conséquence
#- Création du matériau Silicium
#- Modifications mineurs aux codes d'analyse
#- Config en cours : TP reel ENL expérience LULI
#- Passage de la simulation sur 11.0.1

# Commit #13 le 20/05/2022 [TPSim.0.5.4]
#- Ajout des configurations LFEX et PETAL pour comparaison avec donnes expérimentales

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
