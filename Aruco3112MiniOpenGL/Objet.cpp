#include "Objet.h"
#include <fstream>
#include <sstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
using namespace std;
void Objet::LoadTexture(const char* path)
{
    // Load the image using STB Image
    int width, height, channels;
    unsigned char* image = stbi_load(path, &width, &height, &channels, 0);

    if (!image) {
        cout << "Failed to load texture: " << path << endl;
        return;
    }
    GLenum error = glGetError();
    cout << "error: " << error << endl;

    glGenTextures(1, &textureID);
    error = glGetError();
    cout << "error: " << error << endl;
    glBindTexture(GL_TEXTURE_2D, textureID);
    error = glGetError();
    cout << "error: " << error << endl;

    // Set texture parameters for basic rendering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    error = glGetError();
    cout << "error: " << error << endl;
    // Load the image data into the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    error = glGetError();
    cout << "error: " << error << endl;

    // Free the image data
    stbi_image_free(image);
}
void Objet::drawObjet()
{
    float div = 50.0f;
    glBegin(GL_TRIANGLES);
    for (const Face& face : faces) {// affichage de la scène

        // Gris
        glColor3f(1.0f, 1.0f, 1.0f);
        //glColor3f(vertices[face.v1 - 1].r, vertices[face.v1 - 1].v, vertices[face.v1 - 1].b);
        glTexCoord2f(textureCoord[face.vt1 - 1].v1, textureCoord[face.vt1 - 1].v2);
        glVertex3f(vertices[face.v1 - 1].x / div, vertices[face.v1 - 1].y / div, vertices[face.v1 - 1].z / div);
        //glColor3f(vertices[face.v2 - 1].r, vertices[face.v2 - 1].v, vertices[face.v2 - 1].b);
        glTexCoord2f(textureCoord[face.vt2 - 1].v1, textureCoord[face.vt2 - 1].v2);
        glVertex3f(vertices[face.v2 - 1].x / div, vertices[face.v2 - 1].y / div, vertices[face.v2 - 1].z / div);
        //glColor3f(vertices[face.v3 - 1].r, vertices[face.v3 - 1].v, vertices[face.v3 - 1].b);
        glTexCoord2f(textureCoord[face.vt3 - 1].v1, textureCoord[face.vt3 - 1].v2);
        glVertex3f(vertices[face.v3 - 1].x / div, vertices[face.v3 - 1].y / div, vertices[face.v3 - 1].z / div);
    }

    glEnd();
}
GLuint Objet::getTextureID()
{
    return textureID;
}
void Objet::LoadOBJ(const char* filename)
{

    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;

        if (token == "v") { // on ajoute un format du type v x y z
            Vertex vertex;
            iss >> vertex.x >> vertex.y >> vertex.z; //>> vertex.r >> vertex.v >> vertex.b;
            vertices.push_back(vertex);
        }
        else if (token == "f") { // format du type f x/y/z x/y/z x/y/z, où seul les x et y nous interesse. 

            // il s'agit de tout les triplets de points formant des triangles
            Face face;
            char c = 'non';
            iss >> face.v1;
            //passer au point suivant
            while (c != '/') { iss.get(c); }
            iss >> face.vt1;
            c = 'non';
            while (c != '/') { iss.get(c); }
            //while (c != '/') { iss.get(c); }
            iss >> face.normal;
            while (c != ' ') { iss.get(c); }

            iss >> face.v2;
            // ...
            while (c != '/') { iss.get(c); }
            iss >> face.vt2;

            while (c != '/') { iss.get(c); }
            while (c != ' ') { iss.get(c); }

            iss >> face.v3;
            while (c != '/') { iss.get(c); }
            iss >> face.vt3;

            faces.push_back(face);
        }
        else if (token == "vn") {

        }
        // Coordonnées de texture
        else if (token == "vt") {
            Tex tex;
            iss >> tex.v1 >> tex.v2;
            tex.v2 = 1.0 - tex.v2;
            textureCoord.push_back(tex);
        }
    }



    file.close();
}
