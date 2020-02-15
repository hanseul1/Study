# OS(Operating System)

![img](https://k.kakaocdn.net/dn/CtZgi/btqy03C2AlO/cB7uZultInFMPVJVePikh0/img.jpg)



컴퓨터엔 CPU(프로세서), 하드디스크, 메인메모리 존재

 => CPU는 메인메모리에 있는 instruction의 집합(즉, 프로그램)을 실행하는 역할을 하는데,

   메인 메모리의 ROM은 휘발성이기 때문에 OS가 없는 컴퓨터를 켰을 때 메인메모리에는 아무것도 존재하지 않아

   실행할 명령어가 존재하지 않는다.

 

OS의 역할 

: 컴퓨터 하드웨어(하드디스크, CPU, 메인메모리, 모니터, 키보드, 마우스, 네트워크 등)를 잘 관리하여 

성능을 높이고 사용자에게 편의성을 제공하는 역할을 한다.

 

컴퓨터를 키면

-> 메인메모리의 ROM에 저장되어있는 정보를 통해 POST(Power-On Self-Test)를 실행한다. (키보드, 모니터가 연결되어있는지,..등등)

-> Boot loading 실행(하드디스크에 존재하는 OS를 메인메모리로 올린다)

-> OS가 실행되면서 windows는 바탕화면 표시, Linux는 명령 프롬프트 표시

 

OS = shell + kernel 

\- shell은 사용자의 명령을 입력받아 해석하여 결과를 전달해주는 역할을 한다. (command interpreter)

\- kernel은 운영체제의 핵심 역할. 하드웨어 관리, 프로세서 관리 등

 



![img](https://k.kakaocdn.net/dn/nwXNW/btqy1fXw69g/iHCdvIUK9Mv3ZAVQTle0G1/img.png)



 

 

인터럽트 기반 시스템

\- Booting이 끝나면 OS는 컴퓨터가 종료될 때까지 메인 메모리에 상주함(resident)

\- 하드웨어 인터럽트

 : 키보드나 마우스같은 하드웨어의 입력이 들어오면 CPU는 실행하던 것을 멈추고 OS의 Interrupt Service Routine(ISR)을 실행함

\- 소프트웨어 인터럽트 

 : 사용자 프로그램이 실행되면서 swi 명령 실행 -> OS의 ISR 코드를 실행함

 -> 실행 끝나면 다시 사용자 프로그램으로 돌아옴

\- 내부 인터럽트

 : 0으로 나누는 등의 오류가 발생했을 때 CPU가 내부적으로 인터럽트 발생시킴

 

CPU가 메인메모리에 올라온 실행 프로그램의 instruction을 한줄 씩 실행하다가 하드디스크 접근이 필요하거나 printer같은 하드웨어 접근이 필요하면 swi 명령 발생

-> OS에서 관련된 ISR 코드가 실행됨 -> 종료되면 다시 프로그램 명령 실행 

 

 

이중모드

\- 서버 컴퓨터같은 경우 여러명의 사용자가 동시 접속할 수 있음

 => 한 사람의 명령으로 전체 시스템에 영향이 갈 수 있으므로 사용자는 하드디스크나 하드웨어 등을 조작하지 못하도록 함

 => 사용자 모드(user mode)와 관리자 모드(supervisor mode)로 나눔

 

\- CPU의 레지스터에 이중모드 상태를 표시할 flag를 하나 지정(예를 들어 monitor flag)

\- User mode > (키보드, 마우스) > system mode (ISR) > user mode > (모니터, 디스크, 프린터) > system mode > user mode

\- 하드디스크나 하드웨어 접근은 OS만 가능하다.(관리자모드)

 -> 사용자가 STOP같은 특권 명령을 내리려고 하면 CPU는 내부 인터럽트 발생시킴

 

\- 하드웨어 보호

: 입출력장치 보호, 메모리 보호, CPU 보호 