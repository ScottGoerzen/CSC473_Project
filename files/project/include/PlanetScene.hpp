#pragma once

#include "Planet.hpp"
#include "Kite.hpp"

#include <atlas/tools/ModellingScene.hpp>
#include <atlas/utils/FPSCounter.hpp>

namespace lab5
{
    class PlanetScene : public atlas::tools::ModellingScene
    {
    public:
        PlanetScene();

        void updateScene(double time) override;
        void renderScene() override;

    private:
        bool mPlay;
        atlas::utils::FPSCounter mAnimCounter;
        Planet mEarth;
        Planet mSun;
        Kite mKite;

        float mGust;
        float mLength;

        float wind;
    };
}

