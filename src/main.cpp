#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Engine.h"

int main()
{
	Engine engine(1000,800,true);
	engine.run();

	return 0;
}

/*TODO
 *
 *
 * outil "pinceau"
 * outil "ligne"
 * outil "polygone"
 * toolbox "selection de couleur"
 * toolbox polygone "couleur de bordure et couleur de remplissage"
 * toolbox polygone "taille des bords"
 *
 *
 *
 *
 *
 * */