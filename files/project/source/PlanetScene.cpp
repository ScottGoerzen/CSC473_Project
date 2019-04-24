#include "PlanetScene.hpp"

#include <atlas/utils/GUI.hpp>
#include <atlas/gl/GL.hpp>
#include <iostream>

namespace lab5
{
    PlanetScene::PlanetScene() :
        mPlay(false),
        mAnimCounter(60.0f),
        mEarth("earth.jpg"),
        mSun("sun.jpg"),
        mKite("sun.jpg"),
        wind(2)
    {
        mSun.setPosition({ 0.0f, 0.0f, 0.0f });
        mEarth.setPosition({ 25.0f, 0.0f, 25.0f });
        mKite.setPosition({-10, 0, 0});
        mGust = 0;
        mLength = 0.001;
    }

    void PlanetScene::updateScene(double time)
    {
        using atlas::core::Time;

        if (mGust > 0) {
            wind+=.1;
            mGust-=1;
        } else if (mGust < 0) {
            wind-=.1;
            mGust+=1;
        }

        //Fluctuate wind
        float value = 20.0f*mLength;
        float interval = fmodf(mTime.currentTime, value);
        if (interval < value/2) {
            wind+=0.001f;
        } else {
            wind-= 0.001f;
        }

        if (wind < 0) wind = 0;
        if (wind > 8) wind = 8;
        ModellingScene::updateScene(time);
        //if (mPlay && mAnimCounter.isFPS(mTime))
        if (mAnimCounter.isFPS(mTime))
        {

            //mEarth.updateGeometry(mTime);
            mKite.updateGeometry(mTime, wind, mLength);
        }


    }

    void PlanetScene::renderScene()
    {
        using atlas::utils::Gui;
        
        Gui::getInstance().newFrame();
        const float grey = 92.0f / 255.0f;
        glClearColor(0.133f, 0.501f, 0.698f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mProjection = glm::perspective(
            glm::radians(mCamera.getCameraFOV()),
            (float)mWidth / mHeight, 1.0f, 100000000.0f);
        mView = mCamera.getCameraMatrix();

        mGrid.renderGeometry(mProjection, mView);
        mKite.renderGeometry(mProjection, mView);

        // Global HUD
        ImGui::SetNextWindowSize(ImVec2(350, 140), ImGuiSetCond_FirstUseEver);
        ImGui::Begin("Global HUD");
        /*if (mPlay)
        {
            if (ImGui::Button("Pause"))
            {
                mPlay = !mPlay;
            }
        }
        else
        {
            if (ImGui::Button("Play"))
            {
                mPlay = !mPlay;
            }
        }

        if (ImGui::Button("Reset"))
        {
            mEarth.setPosition({ 25.0f, 0.0f, 25.0f });
            mEarth.resetGeometry();
            mPlay = false;
            mTime.currentTime = 0.0f;
            mTime.totalTime = 0.0f;
        }*/

        ImGui::Text("Application average %.3f ms/frame (%.1FPS)",
            1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::InputFloat("Length", &mLength, 0.01f, 5.0f, 1);
        ImGui::InputFloat("Wind", &wind, 0.05f, 5.0f, 1);
        if (ImGui::Button("Cut wind"))
        {
            mGust = -50;
        }
        if (ImGui::Button("Gust"))
        {
            mGust = 15;
        }

        ImGui::End();

        ImGui::Render();
    }
}