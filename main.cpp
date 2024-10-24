#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Categorie {
private:
    int id;  // Identifiant unique de la catégorie
    string nom;  // Nom de la catégorie
    vector<string> listImages;  // Liste des images associées à cette catégorie

public:
    // Constructeur
    Categorie(int id, const string& nom) : id(id), nom(nom) {}

    // Getters
    int getId() const { return id; }
    string getNom() const { return nom; }
    vector<string> getListImages() const { return listImages; }

    // Setters
    void setNom(const string& nouveauNom) { nom = nouveauNom; }

    // Méthodes pour gérer la catégorie
    void creerCategorie(int newId, const string& newNom) {
        id = newId;
        nom = newNom;
        cout << "Catégorie '" << nom << "' créée avec succès.\n";
    }

    void modifierCategorie(const string& nouveauNom) {
        nom = nouveauNom;
        cout << "Catégorie modifiée. Nouveau nom : " << nom << "\n";
    }

    void supprimerCategorie() {
        cout << "Catégorie '" << nom << "' supprimée.\n";
        nom.clear();
        listImages.clear();
    }

    // Méthodes pour gérer les images associées à la catégorie
    void ajouterImage(const string& image) {
        listImages.push_back(image);
        cout << "Image '" << image << "' ajoutée à la catégorie '" << nom << "'.\n";
    }

    void afficherImages() const {
        cout << "Images de la catégorie '" << nom << "':\n";
        for (const auto& img : listImages) {
            cout << " - " << img << "\n";
        }
    }
};

int main() {
    // Création d'une catégorie
    Categorie cat(1, "Nature");

    // Ajout d'images à la catégorie
    cat.ajouterImage("montagne.jpg");
    cat.ajouterImage("plage.jpg");

    // Affichage des images
    cat.afficherImages();

    // Modification de la catégorie
    cat.modifierCategorie("Paysages");

    // Suppression de la catégorie
    cat.supprimerCategorie();

    return 0;
}
