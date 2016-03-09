#ifndef ARDUINO_POWERCONTROLLER_H
#define ARDUINO_POWERCONTROLLER_H


class PowerController {
public:
    bool isOn();

    void switchModeIfNeeded(unsigned long code);

private:
    bool on = true;
};


#endif //ARDUINO_POWERCONTROLLER_H
