#include <iostream>
#include <typedefs.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/TurboLogger.h"

using namespace std;

int main() {
    cout << "Hello world"<<endl;
    return 0;
    TurboLogger* logs = new TurboLogger();
    logs->addLog("testowy");
}