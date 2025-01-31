#include "AwakeTask.h"
#include "Arduino.h"

AwakeTask::AwakeTask(Machine* machine){
  this->machine = machine;
}

void AwakeTask::init(int period){
  Task::init(period);   
}
  
void AwakeTask::tick(){
  if(machine->state == SLEEP){
    if(machine->pir->isPresent()){
      machine->state = READY;
    }
  }
}
