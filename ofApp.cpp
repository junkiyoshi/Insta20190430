#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto radius = 15;
	auto flg = true;
	float sqrt_3 = sqrt(3);
	int threshold = (ofGetFrameNum() * 3) % 600;
	ofColor color;
	for (float y = -ofGetHeight() * 0.5 - radius; y < ofGetHeight() * 0.5 + radius; y += radius * 1.5) {

		for (float x = -ofGetWidth() * 0.5 - radius; x < ofGetWidth() * 0.5 + radius; x += radius * sqrt_3) {

			auto location = flg ? glm::vec2(x, y) : glm::vec2(x + radius * sqrt_3 * 0.5, y);
			auto len = glm::length(location) + 39;
			auto gap = abs(len - threshold);
			color.setHsb(ofRandom(255), 255, 255);

			if (gap < 39) {

				ofPushMatrix();
				ofTranslate(location);

				vector<glm::vec2> vertices;
				for (int deg = 30; deg <= 390; deg += 60) {

					vertices.push_back(glm::vec2((radius - 1) * cos(deg * DEG_TO_RAD), (radius - 1) * sin(deg * DEG_TO_RAD)));
				}

				ofNoFill();
				ofSetColor(color);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofFill();
				ofSetColor(color, ofMap(gap, 0, 39, 255, 0));
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofPopMatrix();
			}
		}
		flg = !flg;
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}