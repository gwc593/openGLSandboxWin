#include <GLFW/glfw3.h>
class vector2 {
public:
    float x, y;

    vector2(float _x, float _y) {
        x = _x;
        y = _y;
    }
    vector2() {
        x = 0;
        y = 0;
    }

    ~vector2() {

    }
};

class triangle {
    
public:
    vector2 position;
    float height;
    float width;

    void draw() 
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(position.x - 0.5* width, position.y);
        glVertex2f(position.x, position.y + height);
        glVertex2f(position.x + 0.5 * width, position.y);
        glEnd();
    }

    void translate(vector2 direction) 
    {
        position.x += direction.x;
        position.y += direction.y;
    }

    triangle(vector2 _base_pos, float _w, float _h) 
    {
        position = _base_pos;
        width = _w;
        height = _h;
    }

    triangle()
    {
    }

    ~triangle() 
    {

    }
};

class square {

public:
    vector2 position;
    float height;
    float width;

    void draw()
    {
        glBegin(GL_QUADS);
        glVertex2f(position.x - (0.5 * width), position.y - (0.5 * height));
        glVertex2f(position.x - (0.5 * width), position.y + (0.5 * height));
        glVertex2f(position.x + (0.5 * width), position.y + (0.5 * height));
        glVertex2f(position.x + (0.5 * width), position.y - (0.5 * height));
        glEnd();
    }

    void translate(vector2 direction)
    {
        position.x += direction.x;
        position.y += direction.y;
    }

    square(vector2 _base_pos, float _w, float _h)
    {
        position = _base_pos;
        width = _w;
        height = _h;
    }

    square()
    {
    }

    ~square()
    {

    }
};

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640*2, 640*2, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    triangle myTri(vector2(0,0),1,1);
    triangle myTri2(vector2(0,0),1,1);
    square mysrq(vector2(0,0),1,1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        myTri.draw();
        myTri.translate(vector2(-0.001,-0.001));

        myTri2.draw();
        myTri2.translate(vector2(0.001, 0.001));
        
        mysrq.draw();
        mysrq.translate(vector2(0.001, -0.001));

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}