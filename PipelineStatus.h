#pragma once
#include <string>
#include <fstream>
#include "Greska.h"
using namespace std;

class PipelineStatus // Singleton pristup
{
    
public:
    static PipelineStatus& getInstance() {
        static PipelineStatus instance; // kreira se samo jednom
        return instance;
    }
    // Tip pozicije cevi
    enum class PipePosition {
        NONE,
        START,
        MIDDLE,
        END
    };

    // Postavljanje i dohvatanje pipe pozicije
    void setPipePosition(PipePosition pos) {
        pipePos = pos;
    }

    PipePosition getPipePosition() const {
        return pipePos;
    }
    void setPipeTempInformation(string tempOutput) {
        tempPipeInformation = tempOutput;
    }

    string getPipeTempInformation() const {
        return tempPipeInformation;
    }
    
    static void changingFileWithPipeTempInformation(string pipeFile) {
        PipelineStatus& cmd = PipelineStatus::getInstance();
        std::ofstream file(pipeFile);
        if (file.is_open()) {
            file << cmd.getPipeTempInformation();
            file.close();
        }
        else {
            throw GNijeMoguceOtvoritiFajl();
        }

    }
private:
    // Privatni konstruktor da se ne može kreirati više instanci
    PipelineStatus() = default;

    // Zabranjeno kopiranje i dodeljivanje
    PipelineStatus(const PipelineStatus&) = delete;
    PipelineStatus& operator=(const PipelineStatus&) = delete;
    
    // Jedna jedina pipe pozicija
    PipePosition pipePos = PipePosition::NONE;
    string tempPipeInformation = "";
};
