//
// Created by Scott Goerzen on 2018-11-14.
//
#pragma once

#include <atlas/utils/Geometry.hpp>
#include <atlas/gl/Buffer.hpp>
#include <atlas/gl/VertexArrayObject.hpp>
#include <atlas/gl/Texture.hpp>

#include <vector>



namespace lab5
{
    class Kite : public atlas::utils::Geometry
    {
    public:
        Kite(std::string const& textureFile);

        void setPosition(atlas::math::Point const& pos);

        void updateGeometry(atlas::core::Time<> const& t, float degrees, float length);
        void renderGeometry(atlas::math::Matrix4 const& projection,
                            atlas::math::Matrix4 const& view) override;

        void resetGeometry() override;

    private:
        std::vector<atlas::math::Vector> mRX;
        std::vector<atlas::math::Vector> mRX0;
        std::vector<atlas::math::Vector> mTX1;
        std::vector<atlas::math::Vector> mTX0;
        float mNumRParts;
        float mL0;
        float mNumTParts;
        float mL1;


        atlas::gl::Buffer mVertexBuffer;
        atlas::gl::Buffer mIndexBuffer;
        atlas::gl::VertexArrayObject mVao;
        atlas::gl::Texture mTexture;

        atlas::gl::Buffer mStringVertexBuffer;
        atlas::gl::Buffer mStringIndexBuffer;
        atlas::gl::VertexArrayObject mStringVao;

        atlas::gl::Buffer mTailVertexBuffer;
        atlas::gl::Buffer mTailIndexBuffer;
        atlas::gl::VertexArrayObject mTailVao;
        int num;

        atlas::math::Point mPos1;
        atlas::math::Point mPos0;
        atlas::math::Point mPosTail;
        atlas::math::Vector mVelocity;
        atlas::math::Vector mWind;
        atlas::math::Vector mWind0;
        atlas::math::Vector mN;
        atlas::math::Vector mForward;
        atlas::math::Vector forward;
        atlas::math::Vector mRight;

        float mTheta0;
        float mTheta1;

        float mChange;


        atlas::math::Vector mStringStart;
        float mStringRest;

        float mCL;
        float mCD;
        float mP;
        float mS;
        float mAlpha;


        GLsizei mIndexCount;

        const float mG = 15.81f;
        const long double PI =  3.141592653589793238462643383279502884L;
    };
}