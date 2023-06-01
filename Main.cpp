//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"



const unsigned int width = 800;
const unsigned int height = 800;

GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	//11
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

//	-0.5f, 0.8f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
//	-0.5f, 0.8f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
//	 0.5f, 0.8f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
//	 0.5f, 0.8f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
//12
	-0.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 0.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 0.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 //13
	-0.5f, 0.0f,  3.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 0.0f, 2.5f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 0.5f, 0.0f, 2.5f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 0.5f, 0.0f,  3.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 //21 22 23
	1.0f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	1.0f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 2.0f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
	 2.0f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 1.0f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	1.0f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 2.0f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 2.0f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 //13
	1.0f, 0.0f,  3.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	1.0f, 0.0f, 2.5f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 2.0f, 0.0f, 2.5f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 2.0f, 0.0f,  3.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 // 31 32 33

	2.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	2.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 3.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
	 3.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 2.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	2.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 3.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 3.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 //13
	2.5f, 0.0f,  3.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	2.5f, 0.0f, 2.5f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 3.5f, 0.0f, 2.5f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 3.5f, 0.0f,  3.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 //ścianki

	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	-0.5f, 1.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 1.0f, -0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 0.5f, 1.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
	 0.5f, 1.0f,  0.5f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 //ścianki 2

	-0.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	-0.5f, 1.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	-0.5f, 1.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,

	-0.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	 0.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	-0.5f, 0.5f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	 0.5f, 0.5f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,


	// ścianki 3

	
	1.0f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 2.0f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 1.0f, 1.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 2.0f, 1.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,

	  1.0f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	 2.0f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 1.0f, 1.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
	 2.0f, 1.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

	 //ścianki 4

	2.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 3.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 2.5f, 1.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    1.0f, 1.0f,
	 3.5f, 1.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,


	 3.5f, 0.0f, 1.0f,     0.83f, 0.70f, 0.44f,	    0.0f, 1.0f,
	 3.5f, 0.0f,  2.0f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
	 3.5f, 0.5f, 1.0f, 0.83f, 0.70f, 0.44f, 0.0f, 1.0f,
	 3.5f, 0.5f, 2.0f, 0.83f, 0.70f, 0.44f, 1.0f, 1.0f,

	 2.5f, 0.0f, 3.5f, 0.83f, 0.70f, 0.44f, 1.0f, 0.0f,
	 2.5f, 0.0f, 2.5f, 0.83f, 0.70f, 0.44f, 1.0f, 1.0f,
	 2.5f, 1.0f, 3.5f, 0.83f, 0.70f, 0.44f, 1.0f, 0.0f,
	 2.5f, 1.0f, 2.5f, 0.83f, 0.70f, 0.44f, 1.0f, 1.0f,


	 3.5f, 0.0f, 2.5f, 0.83f, 0.70f, 0.44f, 0.0f, 1.0f,
	 3.5f, 0.0f, 3.5f, 0.83f, 0.70f, 0.44f, 1.0f, 1.0f,
	 3.5f, 1.0f, 2.5f, 0.83f, 0.70f, 0.44f, 0.0f, 1.0f,
	 3.5f, 1.0f, 3.5f, 0.83f, 0.70f, 0.44f, 1.0f, 1.0f,
};


// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	4,5,6,

	4,6,7,
	8,9,10,
	8,10,11,

	12,13,14,
	12,14,15,

	16,17,18,
	16,18,19,

	20,21,22,
	20,22,23,

	24,25,26,
	24,26,27,

	28,29,30,
	28,30,31,

	32,33,34,
	32,34,35,

	//ścianki
	36,37,38,
	37,38,39,

	40,41,42,
	41,42,43,

	44,45,46,
	45,46,47,

	48,49,50,
	49,50,51,

	52,53,54,
	53,54,55,

	56,57,58,
	57,58,59,

	60,61,62,
	61,62,63,

	64,65,66,
	65,66,67,

	68,69,70,
	69,70,71,

	72,73,74,
	73,74,75,
	
//	0,1,4,
//	1,4,5,
//	1,2,5,
//	2,5,6,
//	2,3,6,
//	3,6,7,
//	0,3,4,
//	3,4,7,
//	4, 5, 6,
//	4, 6, 7,
};

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "Szablonglebokosci", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");


	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string texPath = "/Resources/YoutubeOpenGL 7 - Going 3D/";

	// Texture
	Texture brickTex((parentDir + texPath + "brick.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);

	// Original code from the tutorial
	/*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	brickTex.texUnit(shaderProgram, "tex0", 0);*/



	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f,0.5f, -0.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();

		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		brickTex.Bind();
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);

		glfwPollEvents();

	}


	glDisable(GL_STENCIL_TEST);
	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	brickTex.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}