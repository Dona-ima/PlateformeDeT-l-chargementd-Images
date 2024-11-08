# Plateforme de Banque d'Images avec Authentification

Ce fichier README.md décrit les principales fonctionnalités du projet, sa structure, les prérequis et un exemple d'utilisation. Il peut être complété avec d'autres informations pertinentes, comme les instructions d'installation, les tests, les crédits, etc.

L'objectif est de fournir une documentation claire et concise pour faciliter la compréhension et l'utilisation du projet par d'autres développeurs. N'hésitez pas à poser des questions si vous avez n'importe quelle préoccupation.
Cette application permet de gérer une plateforme de banque d'images avec un système d'authentification.

## Fonctionnalités
- Gestion des galeries d'images
  - Création, modification et suppression de galeries
  - Ajout, suppression et recherche d'images
  - Tri des images par différents critères
-Catégorisation des images
  -Création, modification et suppression des catégories d'images
- Système d'authentification
  - Inscription et connexion d'utilisateurs
  - Gestion des droits d'accès (lecture, écriture, administrateur)
  - Contrôle des actions en fonction du statut de l'utilisateur

## Structure du projet
Le projet est composé des fichiers suivants :

- `Galerie.h` et `Galerie.cpp` : Implémentation de la classe `Galerie` pour gérer les galeries d'images.
- `Utilisateur.h` et `GestionnaireAuth.h` : Implémentation des classes `Utilisateur` et `GestionnaireAuth` pour la gestion de l'authentification.
- `Image.h` : Définition de la classe `Image` pour représenter les images.
- `main.cpp` : Point d'entrée de l'application avec un exemple d'utilisation.

## Prérequis
- Compiler avec un compilateur C++ supportant les fonctionnalités C++11 ou supérieur.

## Utilisation
1. Créer une instance de `GestionnaireAuth` pour gérer l'authentification.
2. Inscrire les utilisateurs en utilisant `GestionnaireAuth::inscrireUtilisateur()`.
3. Connecter les utilisateurs en utilisant `GestionnaireAuth::connecter()`.
4. Créer des instances de `Galerie` en passant le gestionnaire d'authentification en paramètre.
5. Utiliser les méthodes de `Galerie` pour gérer les galeries, en vérifiant les droits d'accès.

Exemple d'utilisation :

```cpp
// Création du gestionnaire d'authentification
GestionnaireAuth auth;

// Inscription d'utilisateurs
auth.inscrireUtilisateur("user1", "pass123", "Jean Dupont", "jean@email.com");
auth.inscrireUtilisateur("user2", "pass456", "Marie Martin", "marie@email.com");

// Création d'une galerie
Galerie galerie(auth);

// Ajout d'images (nécessite d'être connecté)
auth.connecter("user1", "pass123");
galerie.ajouterImage(Image("photo1.jpg"));
galerie.afficherGalerie();
auth.deconnecter();

// Affichage de la galerie (accessible en lecture s'il s'agit d'une galerie publique)
galerie.afficherGalerie();


