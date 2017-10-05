#pragma once

#include <QString>

class DecodeException {
private:
    QString msg;

public:
    DecodeException(const QString& msg): msg(msg) {}

    const QString& getMsg() const {
        return msg;
    }
};
