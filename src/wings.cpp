#include "wings.hpp"

Wings::Wings()
    : m_frontWings('A'), m_backWings('B') {

}

void Wings::setFrontWings(bool value) {
    m_frontWings.set_value(value);
}

void Wings::setBackWings(bool value) {
    m_backWings.set_value(value);
}