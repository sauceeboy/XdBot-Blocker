#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        if (Loader::get()->isModLoaded("zilko.xdbot")) {

            
            bool shouldDisable = Mod::get()->getSettingValue<bool>("disable-if-cheating");

            if (shouldDisable) {
                
                auto mod = Loader::get()->getLoadedMod("zilko.xdbot");
                if (mod) {
                    mod->disable();
                }

                geode::createQuickPopup(
                    "Cheater Detected", 
                    "I caught you <cr>Cheater</c>! I have disabled <cl>XD Bot</c> for you. \nPlease <cy>Restart the Game</c> to apply changes.", 
                    "Ok", "Restart Game",
                    [](auto alert, bool btn2) {
                        if (btn2) {
                            game::restart();
                        }
                    }
                );
            } 
            else {
                
                FLAlertLayer::create(
                    "Cheater Detected", 
                    "I caught you <cr>Cheater</c>! \n(Auto-disable is turned off in settings)", 
                    "Ok"
                )->show();
            }
        }
    }
};