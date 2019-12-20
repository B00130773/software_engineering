#include <iostream>
#include <ctime>
using namespace std;

class Machine
{
class State *current;
public:
Machine();
void setCurrent(State *s)
{
current = s;
}
void sensing_condition();
void idle_condition();
void processing_condition();
};

class State
{
public:
virtual void sensing_condition(Machine *m)
{
cout << "   already in SENSING\n";
}
virtual void idle_condition(Machine *m)
{
cout << "   already in IDLE\n";
}
virtual void processing_condition(Machine *m)
{
cout << "already in PROCESSING\n";
}
};

void Machine::sensing_condition()
{
current->sensing_condition(this);
}

void Machine::idle_condition()
{
current->idle_condition(this);
}

void Machine::processing_condition()
{
current->processing_condition(this);
}


class SENSING_CONDITION: public State
{
public:
SENSING_CONDITION()
{
cout << "   SENSING-ctor ";
};
~SENSING_CONDITION()
{
cout << "   dtor-SENSING\n";
};
void idle_condition(Machine *m);
};

class PROCESSING_CONDITION: public State
{
public:
PROCESSING_CONDITION()
{
cout << "   PROCESSING-ctor ";
};
~PROCESSING_CONDITION()
{
cout << "   dtor-PROCESSING\n";
};
void idle_condition(Machine *m);
};

class IDLE_CONDITION: public State
{
public:
IDLE_CONDITION()
{
cout << "   IDLE-ctor ";
};
~IDLE_CONDITION()
{
cout << "   dtor-IDLE\n";
};
void sensing_condition(Machine *m)
{
cout << "   going from IDLE CONDITION to SENSING CONDITION";
m->setCurrent(new SENSING_CONDITION());
delete this;
}

void processing_condition(Machine *m)
{
cout << "   going from IDLE CONDITION to PROCESSING CONDITION";
m->setCurrent(new PROCESSING_CONDITION());
delete this;
}
};

void SENSING_CONDITION::idle_condition(Machine *m)
{
cout << "   going from SENSING CONDITION to IDLE CONDITION";
m->setCurrent(new IDLE_CONDITION());
delete this;
}
void PROCESSING_CONDITION::idle_condition(Machine *m)
{
cout << "   going from PROCESSING CONDITION to IDLE CONDITION";
m->setCurrent(new IDLE_CONDITION());
delete this;
}

Machine::Machine()
{
current = new IDLE_CONDITION();
cout << '\n';
}
int main()
{
void(Machine:: *ptrs[])() =
{
&Machine::idle_condition, &Machine::sensing_condition, &Machine::processing_condition
};
Machine fsm;
int num;
while(1)
{
cout << " ENTER 0 FOR IDEAL CONDITION--> ENTER 1 FOR SENSING CONDITION--> ENTER 2 FOR PROCESSING CONDITION :";
cin >> num;
(fsm.*ptrs[num])();
}
}
