#include "fmt/core.h"
#include "Magnum/Platform/Sdl2Application.h"

class App : public Magnum::Platform::Application {
public:
    explicit App(const Arguments& arguments): Magnum::Platform::Application(arguments, Magnum::NoCreate) {
        {
            const Magnum::Vector2 dpiScaling = this->dpiScaling({});
            Configuration conf;
            conf.setTitle("Angy Birds").setSize(Magnum::Vector2i(800, 450), dpiScaling);
            GLConfiguration glConf;
            glConf.setSampleCount(dpiScaling.max() < 2.0f ? 8 : 2);
            if (!tryCreate(conf, glConf)) create(conf, glConf.setSampleCount(0));
        }
    }

private:
    void drawEvent() override {
    }
    void mousePressEvent(MouseEvent& event) override {
    }
};

MAGNUM_APPLICATION_MAIN(App)