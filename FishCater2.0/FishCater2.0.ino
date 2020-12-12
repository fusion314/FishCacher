#include <Servo.h>
#define KEY 7
   Servo myservo;  // 定义舵机对象，最多八个
   int pos = 0;    // 定义,舵机转动位置
   int backup = HIGH;
   int keybuf = HIGH;
 
   volatile int flag = LOW;
   
void setup() {
  // put your setup code here, to run once:
 myservo.attach(9);  // 设置舵机控制针脚
  pinMode(KEY,INPUT);//按键检测
   pinMode(6,OUTPUT);//电机1
      pinMode(5,OUTPUT);//电机2
      pinMode(4,OUTPUT);//继电器高电平触发
        
}

void loop() {
  // put your main code here, to run repeatedly:
       digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
         for(pos = 0; pos < 180; pos += 1)  
     {  
      
        myservo.write(pos);  
        delay(10);
        KEYSCAN();
      }
        for(pos = 180; pos>=1; pos-=1)
      {                               
        myservo.write(pos);
         delay(10); 
         KEYSCAN(); 
      }

}
void KEYSCAN()
{
    keybuf = digitalRead(KEY); //把当前扫描值暂存
    if (keybuf!= backup) //当前值与前次值不相等说明此时按键有动作
    {
        delay(10); 
        
        if (keybuf == digitalRead(KEY)) //判断扫描值有没有发生改变，即按键抖动
        {
          if (backup == 0) //如果前次值为 0，则说明当前是弹起动作
          { 

             MOTOR();
          }
        backup = keybuf; //更新备份为当前值，以备进行下次比较
        }
    }
  
}
void MOTOR()
{
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
  delay(8000);
    digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
}
