//
// Created by Scott Goerzen on 2018-11-14.
//

#include "Kite.hpp"
#include "Paths.hpp"
#include "LayoutLocations.glsl"

#include <iostream>

#include <atlas/utils/Mesh.hpp>
#include <atlas/core/STB.hpp>
#include <atlas/math/Coordinates.hpp>
#include <atlas/core/Log.hpp>

namespace lab5 {
    Kite::Kite(std::string const &textureFile) :
            mVertexBuffer(GL_ARRAY_BUFFER),
            mIndexBuffer(GL_ELEMENT_ARRAY_BUFFER),
            mTexture(GL_TEXTURE_2D),
            mStringVertexBuffer(GL_ARRAY_BUFFER),
            mStringIndexBuffer(GL_ELEMENT_ARRAY_BUFFER),
            mTailVertexBuffer(GL_ARRAY_BUFFER),
            mTailIndexBuffer(GL_ELEMENT_ARRAY_BUFFER){
        using atlas::utils::Mesh;
        namespace gl = atlas::gl;
        namespace math = atlas::math;
        using atlas::math::Vector;

        num = 0;
        mPos1 = Vector(-10,0,0);
        mStringStart = Vector(20, 0, 0);
        mPosTail = mPos1 + Vector(-10,0,0);

        mNumRParts = 100;
        mNumTParts = 25;
        
        mL1 = 0.5f;

        for (int i = 0; i < mNumTParts; i++) {
            mTX0.push_back(mPosTail+Vector(-1,0,0)*mL1*float(i));
            mTX1.push_back(mPosTail+Vector(-1,0,0)*mL1*float(i));
        }

        Vector string = mPos1-mStringStart;
        mStringRest = sqrtf(powf(string.x, 2) + powf(string.y, 2) + powf(string.z, 2));
        mRX.push_back(mStringStart);
        mRX0.push_back(mStringStart);

        mL0 = mStringRest/mNumRParts;
        mL0 = 0.001;
        string = glm::normalize(string);
        mPos1 = string*mNumRParts*mL0;
        mPos0 = mPos1;

        for (int i = 1; i < mNumRParts; i++) {

            mRX.push_back(mStringStart+(string*float(i)*mL0));
            mRX0.push_back(mStringStart+(string*float(i)*mL0));
        }

        mRX.push_back(mPos1);
        mRX0.push_back(mPos1);
        mNumRParts++;

        Mesh sphere;
        std::string path{DataDirectory};
        path = path + "kite.obj";
        Mesh::fromFile(path, sphere);

        mIndexCount = static_cast<GLsizei>(sphere.indices().size());

        std::vector<float> data;
        for (std::size_t i = 0; i < sphere.vertices().size(); ++i) {
            data.push_back(sphere.vertices()[i].x);
            data.push_back(sphere.vertices()[i].y);
            data.push_back(sphere.vertices()[i].z);

            data.push_back(sphere.vertices()[i].x);
            data.push_back(sphere.vertices()[i].y);
            data.push_back(sphere.vertices()[i].z);

            data.push_back(sphere.vertices()[i].x);
            data.push_back(sphere.vertices()[i].y);
        }

        std::vector<float> tailData;
        for (std::size_t i = 0; i < mNumTParts; i++) {
            tailData.push_back(mTX1[i].x);
            tailData.push_back(mTX1[i].y);
            tailData.push_back(mTX1[i].z);
        }
        std::vector<float> tailIndicies;
        for (float i = 0; i<mNumTParts-1; i++) {
            tailIndicies.push_back(i);
            tailIndicies.push_back(i+1);
        }

        std::vector<float> stringData;
        for (std::size_t i = 0; i < mNumRParts; i++) {
            stringData.push_back(mRX[i].x);
            stringData.push_back(mRX[i].y);
            stringData.push_back(mRX[i].z);
        }
        std::vector<float> stringIndicies;
        for (float i = 0; i<mNumRParts-1; i++) {
            stringIndicies.push_back(i);
            stringIndicies.push_back(i+1);
        }

        mTailVao.bindVertexArray();
        mTailVertexBuffer.bindBuffer();
        mTailVertexBuffer.bufferData(gl::size<float>(tailData.size()), tailData.data(), GL_STREAM_DRAW);
        mTailVertexBuffer.vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, gl::stride<float>(0), gl::bufferOffset<float>(0));

        mTailVao.enableVertexAttribArray(0);

        mTailIndexBuffer.bindBuffer();
        mTailIndexBuffer.bufferData(gl::size<float>(tailIndicies.size()), tailIndicies.data(), GL_STATIC_DRAW);
        mTailIndexBuffer.unBindBuffer();
        mTailVertexBuffer.unBindBuffer();
        mTailVao.unBindVertexArray();

        //----------------------------------------------------------------------------------------

        mStringVao.bindVertexArray();
        mStringVertexBuffer.bindBuffer();
        mStringVertexBuffer.bufferData(gl::size<float>(stringData.size()), NULL, GL_STREAM_DRAW);
        mStringVertexBuffer.vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, gl::stride<float>(0), gl::bufferOffset<float>(0));

        mStringVao.enableVertexAttribArray(0);

        mStringIndexBuffer.bindBuffer();
        mStringIndexBuffer.bufferData(gl::size<float>(stringIndicies.size()), stringIndicies.data(), GL_STATIC_DRAW);
        mStringIndexBuffer.unBindBuffer();
        mStringVertexBuffer.unBindBuffer();
        mStringVao.unBindVertexArray();

        //----------------------------------------------------------------------------------------------

        mVao.bindVertexArray();
        mVertexBuffer.bindBuffer();
        mVertexBuffer.bufferData(gl::size<float>(data.size()), data.data(), GL_STATIC_DRAW);
        mVertexBuffer.vertexAttribPointer(VERTICES_LAYOUT_LOCATION, 3, GL_FLOAT,
                                          GL_FALSE, gl::stride<float>(8), gl::bufferOffset<float>(0));
        mVertexBuffer.vertexAttribPointer(NORMALS_LAYOUT_LOCATION, 3, GL_FLOAT,
                                          GL_FALSE, gl::stride<float>(8), gl::bufferOffset<float>(3));
        mVertexBuffer.vertexAttribPointer(TEXTURES_LAYOUT_LOCATION, 2, GL_FLOAT,
                                          GL_FALSE, gl::stride<float>(8), gl::bufferOffset<float>(6));

        mVao.enableVertexAttribArray(VERTICES_LAYOUT_LOCATION);
        mVao.enableVertexAttribArray(NORMALS_LAYOUT_LOCATION);
        mVao.enableVertexAttribArray(TEXTURES_LAYOUT_LOCATION);

        mIndexBuffer.bindBuffer();
        mIndexBuffer.bufferData(gl::size<GLuint>(sphere.indices().size()),
                                sphere.indices().data(), GL_STATIC_DRAW);

        mIndexBuffer.unBindBuffer();
        mVertexBuffer.unBindBuffer();
        mVao.unBindVertexArray();

        int width, height, nrChannels;
        std::string imagePath = std::string(DataDirectory) + textureFile;
        unsigned char *imageData = stbi_load(imagePath.c_str(), &width, &height,
                                             &nrChannels, 0);

        mTexture.bindTexture();
        mTexture.texImage2D(0, GL_RGB, width, height, 0,
                            GL_RGB, GL_UNSIGNED_BYTE, imageData);
        mTexture.texParameteri(GL_TEXTURE_WRAP_S, GL_REPEAT);
        mTexture.texParameteri(GL_TEXTURE_WRAP_T, GL_REPEAT);
        mTexture.texParameteri(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        mTexture.texParameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(imageData);

        std::vector<gl::ShaderUnit> stringShaders
                {
                        {std::string(ShaderDirectory) + "String.vs.glsl", GL_VERTEX_SHADER},
                        {std::string(ShaderDirectory) + "String.fs.glsl", GL_FRAGMENT_SHADER}
                };

        std::vector<gl::ShaderUnit> shaders
                {
                        {std::string(ShaderDirectory) + "Planet.vs.glsl", GL_VERTEX_SHADER},
                        {std::string(ShaderDirectory) + "Planet.fs.glsl", GL_FRAGMENT_SHADER}
                };

        std::vector<gl::ShaderUnit> tailShaders
                {
                        {std::string(ShaderDirectory) + "Tail.vs.glsl", GL_VERTEX_SHADER},
                        {std::string(ShaderDirectory) + "Tail.fs.glsl", GL_FRAGMENT_SHADER}
                };

        mShaders.emplace_back(shaders);
        mShaders.emplace_back(stringShaders);
        mShaders.emplace_back(tailShaders);
        mShaders[0].setShaderIncludeDir(ShaderDirectory);
        mShaders[1].setShaderIncludeDir(ShaderDirectory);
        mShaders[2].setShaderIncludeDir(ShaderDirectory);
        mShaders[0].compileShaders();
        mShaders[1].compileShaders();
        mShaders[2].compileShaders();
        mShaders[0].linkShaders();
        mShaders[1].linkShaders();
        mShaders[2].linkShaders();

        auto var = mShaders[0].getUniformVariable("model");
        mUniforms.insert(UniformKey("model", var));
        var = mShaders[0].getUniformVariable("projection");
        mUniforms.insert(UniformKey("projection", var));
        var = mShaders[0].getUniformVariable("view");
        mUniforms.insert(UniformKey("view", var));
        mShaders[0].disableShaders();

        auto svar = mShaders[1].getUniformVariable("model");
        mUniforms.insert(UniformKey("smodel", svar));
        svar = mShaders[1].getUniformVariable("projection");
        mUniforms.insert(UniformKey("sprojection", svar));
        svar = mShaders[1].getUniformVariable("view");
        mUniforms.insert(UniformKey("sview", svar));
        mShaders[1].disableShaders();

        auto tvar = mShaders[2].getUniformVariable("model");
        mUniforms.insert(UniformKey("tmodel", tvar));
        tvar = mShaders[2].getUniformVariable("projection");
        mUniforms.insert(UniformKey("tprojection", tvar));
        tvar = mShaders[2].getUniformVariable("view");
        mUniforms.insert(UniformKey("tview", tvar));
        mShaders[2].disableShaders();

        mModel = glm::scale(math::Matrix4(1.0f), math::Vector(0.5f));

        Vector v1Plane = glm::normalize(sphere.vertices()[2]-sphere.vertices()[0]);
        Vector v2Plane = glm::normalize(sphere.vertices()[3]-sphere.vertices()[1]);
        mForward = v1Plane;
        mRight = v2Plane;
        mN = glm::normalize(glm::cross(mForward, mRight));
        mAlpha = acosf((pow(mForward.x*1, 2))/(pow(mForward.x, 2)+pow(mForward.y, 2)+pow(mForward.z, 2)));
    }

    void Kite::setPosition(atlas::math::Point const &pos) {
        using atlas::math::Matrix4;
        using atlas::math::Vector;

        mCL = 1;
        mP = 1.229f;
        mS = 15*5;
        mCD = 1;

        mTheta1 = 10;
        mTheta0 = 10;

        mChange = 0;

        mWind = atlas::math::Vector(-1.0,0,0);
        mWind0 = atlas::math::Vector(-1.0,0,0);

        mModel = glm::translate(Matrix4(1.0f), mPos1)*glm::rotate(Matrix4(1.0f), glm::radians(mTheta1), Vector(0,0,1));
        forward = mForward * atlas::math::Matrix3(glm::transpose(mModel));
        Vector right = mRight * atlas::math::Matrix3(mModel);
        mN = glm::normalize(glm::cross(forward, right));
        mAlpha = acos(sqrtf((pow(forward.x*1, 2))/(pow(forward.x, 2)+pow(forward.y, 2)+pow(forward.z, 2))));
    }

    void Kite::updateGeometry(atlas::core::Time<> const &t, float degrees, float length) {
        using atlas::math::Matrix4;
        using atlas::math::Vector;
        using atlas::math::polarToCartesian;

        mWind.x = -degrees;
        mL0 = length;

        //Update lift and drag coefficients
        if (mAlpha > 45) {
            mCL = sin(2*45)*sin(2*mAlpha);
            mCD = (1-cos(2*45))*(1-cos(2*mAlpha));
        } else {
            mCL = sin(2*mAlpha);
            mCD = 1-cos(2*mAlpha);
        }

        //Calculate forces of gravity, lift, and drag
        Vector Ag = mG * Vector(0, -1, 0);
        Vector L = 0.5f * mCL * mP * mS * glm::cross((glm::cross(mWind, mN)),mWind);
        Vector D = 0.5f * mCD * mP * mS * glm::abs(mWind) * mWind;

        float W = 10.0f;

        //Torque, not using right now
        float T = -L.y*cos(2*mAlpha)-D.x*cos(mAlpha)-W*cos(mAlpha);

        L *= 1;
        D *= 1;

        //Accumulate forces -> ignoring mass (m = 1) to make it easier
        Vector accel = Ag+L+D;//+Fstring;

        accel *= 5;

        //Integrate position
        Vector pos;

        if (L.y != 0 or D.x !=0) {
            pos = 2.0f * mPos1 - mPos0 + (t.deltaTime*t.deltaTime) * (accel);
            mPos0 = mPos1;
            mPos1 = pos;
        } else {
            pos = 2.0f * mPos1 - mPos0 + (t.deltaTime*t.deltaTime) * Ag;
            mPos0.y = mPos1.y;
            mPos1.y = pos.y;
        }

        //Integrate rotation
        float theta;
        theta =  (t.deltaTime) * T/(1);
        mTheta0 = mTheta1;
        mTheta1 = theta;

        float windChange = mWind.x-mWind0.x;
        //Find rotation
        float fRotation = mAlpha*180/PI;
        fRotation-=mTheta1;
        fRotation+=(windChange);

        if (windChange > 0) {
            mWind0.x += 0.1;
        } else if (windChange < 0) {
            mWind0.x -= 0.1;
        }

        if (mWind.x > mWind0.x) mChange = 1000;
        if (mChange > 0) mChange -= 10;

        //Update string positions
        mRX[mNumRParts-1] = mPos1;
        float pointMass = 0.5f;
        for (int i = mNumRParts-2; i > 0; i--) {
            atlas::math::Point p;

            p = 2.0f * mRX[i] - mRX0[i] + (t.deltaTime*t.deltaTime)*((Ag*pointMass));
            Vector dir = p-mRX[i];
            float dist = sqrtf(glm::dot(dir, dir));
            mRX0[i] = mRX[i]+glm::normalize(dir)*dist*0.05f;

            p = mRX[i + 1] + (glm::normalize(p - mRX[i + 1]) * mL0);
            mRX[i] = p;
        }

        //Constrain string positions and pull kite
        for (int i = 1; i < mNumRParts; i++) {
            atlas::math::Point p;
            Vector dist = mRX[i]-mRX[i-1];
            //Point constraints
            if (glm::dot(dist, dist) > powf(mL0*1.0f, 2.0f)) {
                p = mRX[i - 1] + (glm::normalize(dist) * mL0);
                mRX[i] = p;
            }

            if (mRX[i].y < -0.1) mRX[i].y = -0.1;
            if (mRX0[i].y < -0.1) mRX0[i].y = -0.1;
        }
        if (L.y != 0 or D.x != 0) mPos1 = mRX[mNumRParts-1];

        if (mPos1.y < 0) mPos1.y = 0;
        if (mPos0.y < 0) mPos0.y = 0;

        mModel = glm::translate(Matrix4(1.0f), mPos1)*glm::rotate(Matrix4(1.0f), glm::radians(fRotation), Vector(0,0,1));

        //Update angle
        forward = mForward * atlas::math::Matrix3(glm::transpose(mModel));
        Vector right = mRight * atlas::math::Matrix3(mModel);
        mN = glm::normalize(glm::cross(forward, right));
        mAlpha = acos(sqrtf((pow(forward.x*1, 2))/(pow(forward.x, 2)+pow(forward.y, 2)+pow(forward.z, 2))));
        if (forward.y < 0) mAlpha *= -1;

        //Update tail position
        pointMass = 3.0f;
        mTX1[0] = mPos1 + glm::normalize(forward)*-10.0f;
        for (int i = 1; i < mNumTParts; i++) {
            atlas::math::Point p;

            p = 2.0f * mTX1[i] - mTX0[i] + (t.deltaTime*t.deltaTime)*((Ag*pointMass)+(D*pointMass/2.0f));
            Vector dir = p-mTX1[i];
            float dist = sqrtf(glm::dot(dir, dir));
            mTX0[i] = mTX1[i] + glm::normalize(dir) * dist * 0.2f;
            p = mTX1[i - 1] + (glm::normalize(p - mTX1[i - 1]) * mL1);
            mTX1[i] = p;
        }
    }

    void Kite::renderGeometry(atlas::math::Matrix4 const &projection,
                                atlas::math::Matrix4 const &view) {
        namespace math = atlas::math;
        namespace gl = atlas::gl;

        for (int i = 0; i < 3; i++) {
            mShaders[i].hotReloadShaders();
            if (!mShaders[i].shaderProgramValid()) {
                return;
            }
        }

        std::vector<float> newStringData;
        for (std::size_t i = 0; i < mRX.size(); i += 1) {
            newStringData.push_back(mRX[i].x);
            newStringData.push_back(mRX[i].y);
            newStringData.push_back(mRX[i].z);
        }


        mStringVertexBuffer.bindBuffer();
        mStringVertexBuffer.bufferSubData(0, gl::size<float>(newStringData.size()), newStringData.data());
        mStringVertexBuffer.unBindBuffer();


        std::vector<float> tailData;
        for (std::size_t i = 0; i < mNumTParts; i++) {
            tailData.push_back(mTX1[i].x);
            tailData.push_back(mTX1[i].y);
            tailData.push_back(mTX1[i].z);
        }
        mTailVertexBuffer.bindBuffer();
        mTailVertexBuffer.bufferSubData(0, gl::size<float>(tailData.size()), tailData.data());
        mTailVertexBuffer.unBindBuffer();



        // Print out string points
        DEBUG_LOG_V("#=========================================#");
        for (std::size_t i = 0; i < newStringData.size(); i += 3)
        {
            DEBUG_LOG_V("(%f, %f, %f)",
                        newStringData[i + 0],
                        newStringData[i + 1],
                        newStringData[i + 2]);
        }

        for (std::size_t i = 0; i < tailData.size(); i += 3)
        {
            //std::cout<<tailData[i]<<", ";
            //std::cout<<tailData[i+1]<<", ";
            //std::cout<<tailData[i+2]<< "   :   ";
        }
        std::cout<<std::endl;



        // -----------------------------------------------------------------------------------------------

        mShaders[1].enableShaders();

        mStringVao.bindVertexArray();

        auto smodel = atlas::math::Matrix4(1.0f);
        glUniformMatrix4fv(mUniforms["smodel"], 1, GL_FALSE, &smodel[0][0]);
        glUniformMatrix4fv(mUniforms["sprojection"], 1, GL_FALSE,
                           &projection[0][0]);
        glUniformMatrix4fv(mUniforms["sview"], 1, GL_FALSE, &view[0][0]);

        glDrawArrays(GL_LINE_STRIP, 0, mRX.size());

        mStringVao.unBindVertexArray();
        mShaders[1].disableShaders();

        // -----------------------------------------------------------------------------------------------

        mShaders[2].enableShaders();
        mTailVao.bindVertexArray();



        auto tmodel = atlas::math::Matrix4(1.0f);
        glUniformMatrix4fv(mUniforms["tmodel"], 1, GL_FALSE, &tmodel[0][0]);
        glUniformMatrix4fv(mUniforms["tprojection"], 1, GL_FALSE,
                           &projection[0][0]);
        glUniformMatrix4fv(mUniforms["tview"], 1, GL_FALSE, &view[0][0]);

        GLfloat lineWidthRange[2];
        glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);

        glDrawArrays(GL_LINE_STRIP, 0, mTX1.size());

        mTailVao.unBindVertexArray();
        mShaders[2].disableShaders();

        // -----------------------------------------------------------------------------------------------

        mShaders[0].enableShaders();
        mTexture.bindTexture();
        mVao.bindVertexArray();
        mIndexBuffer.bindBuffer();

        glUniformMatrix4fv(mUniforms["model"], 1, GL_FALSE, &mModel[0][0]);
        glUniformMatrix4fv(mUniforms["projection"], 1, GL_FALSE,
                           &projection[0][0]);
        glUniformMatrix4fv(mUniforms["view"], 1, GL_FALSE, &view[0][0]);

        glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);

        mIndexBuffer.unBindBuffer();
        mVao.unBindVertexArray();
        mTexture.unBindTexture();
        mShaders[0].disableShaders();
    }

    void Kite::resetGeometry() {
    }
}