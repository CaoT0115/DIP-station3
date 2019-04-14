#include   <IRremote.h>                 // 引用 IRRemote 函式库

const int irReceiverPin = 12;             // 红外线接收器 OUTPUT 讯号接在 pin 2
int gate = 5;

IRrecv irrecv(irReceiverPin);            // 定义 IRrecv 物件来接收红外线讯号
decode_results results;                  // 解码结果将放在 decode_results 结构的 result 变数里

void setup()
{
  Serial.begin(9600);                     // 开启 Serial port, 通讯速率为 9600 bps
  irrecv.enableIRIn();                   // 启动红外线解码
  pinMode(13,OUTPUT);
  pinMode(gate,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() 
{
  digitalWrite(9,1);
  if (irrecv.decode(&results)) {         // 解码成功，收到一组红外线讯号
    Serial.println(results.value, HEX);// 显示红外线协定种类

    if(results.value==0x806F00FF)
    {
      digitalWrite(13,1);
      digitalWrite(gate,1);
      delay(500);
      Serial.println("correct");
      
      digitalWrite(13,0);
      //digitalWrite(gate,0);
      delay(500);
    }
    else{
      digitalWrite(gate,0);
      digitalWrite(13,1);
    }
    irrecv.resume();                     // 继续收下一组红外线讯号        
  }  
}
