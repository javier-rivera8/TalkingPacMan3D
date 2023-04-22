#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //pacman frames---------------------------------------------
    pacDown.load("PACTECA1.png");
    pacMiddle.load("PACTECA2.png");
    pacHear.load("PACTECA5.png");
    pacTalk.load("PACTECA3.png");
    pacFullOpen.load("PACTECA4.png");

    //assetes---------------------------------------------------
    troll.load("TROLL1.mp3");
    bread.load("Pan2.png");
    menu.load("menu2.png");
    settings.load("menu3.png");
}

//--------------------------------------------------------------
void ofApp::update(){

    if(posX > 600 && posY < 800 && posX < 1300 && posY > 100 && realease ){
        eat = true;
    }
    else{
        eat = false;
    }

    if(eat == false){
        eatcntr = 0;
    }

    if(food == false){
        xPan = 175;
        yPan = ofGetHeight() - 300;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cntr += 1;
    hlthcntr += 1;

    if(hear == false && talk == false && eat == false){
        if(cntr < 30){
            pacDown.draw(0, 0);
        }
        if(cntr >= 30){
            pacMiddle.draw(0, 0);
        }
        if(cntr == 60){
            this->cntr = 0;
        } 
    }
    
    if(hear){
        pacHear.draw(0, 0);
        cntr = 0;
    }

    if(talk){
        if(talkcntr == 0){
            troll.play();
        }
        if(cntr < 10){
            pacDown.draw(0, 0);
        }
        if(cntr >= 10){
            pacTalk.draw(0, 0);
        }
        if(cntr == 20){
            this->cntr = 0;
            this->talkcntr += 1;
        } 
        if(talkcntr == 5){
            this->talkcntr = 0;
            talk = false;
        }
        
    }
    if(eat){
        eatcntr += 1;

        if(eatcntr < 3){
            pacTalk.draw(0, 0);
        }
        if(eatcntr >= 3){
            pacFullOpen.draw(0, 0);
            cntr = 0;
        }
        
    }
    if(pause){
        settings.draw(0,0);
    }

    // if(eating){
    //     eatanim += 1;
    //     if(eatingcnt == 0){
    //         troll.play();
    //     }
    //     if(eatanim < 5){
    //         pacDown.draw(0, 0);
    //     }
    //     if(eatanim >= 5 && eatanim < 10){
    //         pacTalk.draw(0, 0);
    //     }
    //     if(eatanim >= 10){
    //         pacFullOpen.draw(0, 0);
    //     }
    //     if(eatanim == 15){
    //         this->eatanim = 0;
    //         this->eatingcnt += 1;
    //     } 
    //     if(eatingcnt == 3){
    //         this->eatingcnt = 0;
    //         eating = false;
    //     }
    // }
    if(hlthBar > 0){
        if(hlthcntr%15==0){
           hlthBar -= 1; 
        }
        
    }
    else{
        minus = 0;
    }

    if(hlthBar > 500){
        ofSetColor(ofColor::green);
    }
    else if(hlthBar > 300){
        ofSetColor(ofColor::yellow);
    }
    else{
        ofSetColor(ofColor::red);
    }
    ofFill();
    ofDrawRectangle(ofGetWidth()/2 - 300, ofGetHeight() - 100, hlthBar, 20);
    ofSetColor(ofColor::white);
    menu.draw(0, 0);
    ofNoFill();
    ofDrawRectangle(ofGetWidth()/2 - 300, ofGetHeight() - 100, 650, 20);
    ofFill();
    bread.draw(xPan, yPan, 200, 200);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'p'){
        pause = !pause;
    }
    if( key == 't'){
        if(hear){
            hear = false;
            talk = true;
            
        }
        else if(hear == false){
            hear = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if( button == 0){
        posX = x;
        posY = y;
        xPan = x -100;
        yPan = y - 100;
        food = true;
        realease = true;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if( button == 0){
        eat = false;
        realease = false;
        food = false;
        if(posX > 600 && posY < 800 && posX < 1300 && posY > 100){
            if(hlthBar + 100 > 650){
                hlthBar = 650;
            }
            else{
                hlthBar += 100;
            }
            // eating = true;
            
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}