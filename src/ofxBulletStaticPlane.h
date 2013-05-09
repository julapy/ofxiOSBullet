//
//  ofxBulletStaticPlane.h
//  emptyExample
//
//  Created by Lukasz Karluk on 18/12/12.
//
//

#pragma once

#include "ofMain.h"

class btDynamicsWorld;
class btStaticPlaneShape;
class btRigidBody;

class ofxBulletStaticPlane {
    
public:
    
    ofxBulletStaticPlane();
    ~ofxBulletStaticPlane();
    
    virtual void destroy();
    virtual void setup(btDynamicsWorld * world, ofPoint planePosition, ofPoint planeNormal, float planeConstant=1);
    virtual void setupFloor(btDynamicsWorld * world, ofPoint planePosition);
    virtual void setupCeiling(btDynamicsWorld * world, ofPoint planePosition);
    virtual void update();
    virtual void draw();

    btDynamicsWorld * world;
    btStaticPlaneShape * shape;
    btRigidBody * rigidBody;
};
