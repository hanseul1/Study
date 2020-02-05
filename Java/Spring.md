# Spring

## spring framework

#### 장점

## DI(Dependency Injection)

## IoC(Inversion of Control)

## Servlet

#### Servlet Container

## JSP

#### MVC1 패턴과 MVC2 패턴

- MVC1 패턴
  - 모든 클라이언트의 요청과 응답을 JSP가 담당한다.
  - 즉, JSP에 view 코드(html)와 controller 코드(java)가 함께 존재한다.
  - 각 코드의 재사용성이 떨어져 유지보수가 어려워지고 효율성이 떨어진다.
- MVC2 패턴
  - controller 역할은 servlet이, view 역할은 JSP가 담당한다.
  - 서블릿이 클라이언트의 요청을 받아 처리 후 결과를 JSP 페이지에 포워딩 한다.
  - 코드의 유지보수 및 확장이 용이하다.

## Spring MVC

#### Spring Container

- 어플리케이션의 Bean들의 생명주기를 관리하는 컨테이너

  => 개발자가 직접 인터페이스 호출, new 연산자로 객체 생성 등을 통해 의존성을 만들지 않아도 된다.

- bean을 관리하기 위해 DI(Dependency Injection)를 사용한다.



#### 웹 어플리케이션 동작 원리

![img](https://i.imgur.com/PlDF42i.png)

- Dispatcher servlet : 서블릿 컨테이너에서 HTTP 프로토콜을 통해 들어오는 모든 클라이언트의 요청을 presentation 계층의 제일 앞에서 중앙집중식으로 처리해주는 Front Controller 역할
  - 기존의 servlet
    - web.xml에 servlet과 url 패턴을 등록하고 매핑하는 과정이 필요하다.
    - 즉, url 당 새로운 servlet을 생성하여 요청을 처리해야 했다.
  - Front Controller
    - 하나의 Servlet에서 모든 요청을 받아들여 적절한 controller로 요청을 위임해준다.

- 참고 : https://minwan1.github.io/2017/10/08/2017-10-08-Spring-Container,Servlet-Container/