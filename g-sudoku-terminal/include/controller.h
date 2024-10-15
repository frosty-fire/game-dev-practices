#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>

class Controller {
    int threadId;

public:
    void run();

    std::string getKeyPressed() const;
};

#endif //CONTROLLER_H
