#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "fmt/core.h"

int main(int argc, char* args[]) {
    fmt::print("Hello from CXX!\n");
    OgreBites::ApplicationContext ctx("MyApp");
    ctx.initApp();
    return 0;
}