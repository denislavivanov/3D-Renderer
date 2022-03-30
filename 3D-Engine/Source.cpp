#include "Renderer.h"



int main(int argc, char** argv)
{
    if (argc > 2)
    {
        std::cerr << "usage: [engine].exe scene_path" << std::endl;
        return -1;
    }

    Renderer renderer(argv[1]);

    renderer.Run();

    return 0;
}
