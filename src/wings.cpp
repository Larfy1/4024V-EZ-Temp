#include "wings.hpp"

Wings::Wings()
    : m_frontWings('A'), m_backWingL('B'), m_backWingR('C') {

}

void Wings::setFrontWings(bool value) {
    m_frontWings.set_value(value);
}

void Wings::setBackWingL(bool value) {
    m_backWingL.set_value(value);
}

void Wings::setBackWingR(bool value) {
    m_backWingR.set_value(value);
}