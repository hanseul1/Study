# Spring

## Spring & Spring MVC & Spring Boot

#### Spring

- Spring의 가장 큰 특징은 DI(Dependency Injection) 이다. 
- DI와 IoC(Inversion of Control)를 활용하여 개발자는 어플리케이션의 전체 흐름에 관여하지 않고 비즈니스 로직에만 집중할 수 있다.
- 또한 Spring은 많은 Spring 모듈들을 이용해서 다양한 기능을 제공한다.
  - Spring JDBC
  - Spring AOP
  - Spring MVC
  - Spring ORM
  - Spring Test

#### Spring MVC

- Dispatcher Servlet, ModelAndView, View Resolver와 같은 개념을 이용해서 웹 어플리케이션 개발을 쉽게 할 수 있도록 도와준다.

#### Spring Boot

- Spring 어플리케이션의 경우 다양한 bean에 대한 설정을 해주어야한다.(XML 또는 JAVA 코드)
  - component scan(DTO, DAO, Service)
  - Dispatcher Servlet
  - View Resolver
  - 등등
- Auto Configuration
  - classpath 상에 사용가능한 프레임워크와 이미있는 환경 설정을 기반으로 기본환경 설정을 제공한다.
  - 예를들어, MySQL jar가 클래스패스 상에 있을 경우 Datasource를 자동으로 구성한다.
  - 또한, Spring MVC jar가 클래스패스 상에 있을 경우 Dispatcher Servlet을 자동으로 구성한다.

- 의존 라이브러리나 프레임워크의 버전 관리
  - 기존에는 웹 어플리케이션에 필요한 Spring MVC, Jackson Databind 같은 라이브러리 또는 프레임워크를 의존할 때, 모든 프레임워크들이 호환되는 버전을 선택해야 했다.
  - Spring boot는 pom.xml에 의존할 라이브러리나 프레임워크 종속성만 포함시키고 바로 진행할 수 있게한다.(알아서 버전 관리를 해준다.)

참고 : http://blog.naver.com/PostView.nhn?blogId=sthwin&logNo=221271008423&parentCategoryNo=&categoryNo=50&viewDate=&isShowPopularPosts=true&from=search



## DI(Dependency Injection)

#### Java Bean VS Spring Bean

- Java Bean은 데이터를 표현하는 것을 목적으로 하는 자바 클래스
  - 생성자, getter/setter 를 가지고, 직렬화가 가능한 클래스
- Spring Bean은 Spring container에 의해 등록, 생성, 조회, 관계 설정이 되는 객체
  - 즉, IoC 방식으로 관리되는 객체를 말한다.

#### 일반적인 의존 관계와 의존 역전 원칙

- 일반적인 의존 관계
  - 일반적인 프로그램의 흐름에 따라 객체 내에서 필요한 객체가 있을 때, 필요한 객체를 직접 생성하고, 직접 객체의 메소드를 호출한다.
  - 즉, 모든 작업은 사용하는 쪽에서 제어한다.
- 의존 역전 원칙(DIP, Dependency Inversion Principle)
  - 객체 내에서 필요한 객체가 있을 때, 직접 객체를 생성하는 것이 아니라, 생성된 객체를 받아서 사용한다.
  - 또한 사용할 객체의 구현 클래스가 아닌 인터페이스를 사용함으로써 실제 객체가 어떤 타입이든 관계없이 같은 코드를  사용할 수 있다.
  - 즉, 객체간의 의존 관계가 뒤집어진 의존 역전 원칙이 되는 것이다.

#### BeanFactory & ApplicationContext

- BeanFactory
  - Bean을 생성하고 관리하는 인터페이스
  - 클라이언트의 요청이 있을 때 객체를 생성한다.(lazy-init)
- ApplicationContext
  - BeanFactory 인터페이스를 상속받은 인터페이스
  - 컨테이너가 구동되는 시점에 등록된 Bean 객체들을 모두 스캔하여 생성한다.(eager init)

#### Annotation

- bean 등록 annotation
  - `@Bean` : 개발자가 컨트롤할 수 없는 외부 라이브러리 bean을 등록하고 싶은 경우
  - `@Component` : 개발자가 직접 만든 클래스를 bean으로 등록하고 싶은 경우
  - `@Controller` `@Service` `@Repository` : 클래스의 기능에 따라 명칭을 다르게 부여한 bean
- bean 주입 annotation
  - `@Autowired` : 타입으로 참조할 bean을 찾아 주입
    - `@Qualifier`  : 같은 인터페이스를 구현한 클래스가 여러개 일때, 이름으로 구별해주기 위한 annotation
  - `@Resource` : 이름으로 참조할 bean을 찾아 주입

#### Bean 생성 순서

- 의존 관계가 있는 경우

  - 각 Bean들이 순서대로 생성, 초기화된다. 

    - Spring에서는 web.xml에 선언된 순서대로
    - Spring boot 에서는 패키지 순서대로 

  - Bean 생성 중 의존하고 있는 Bean이 존재할 때 

    - 의존하는 Bean이 아직 생성되지 않은 경우 먼저 해당 Bean을 생성 및 초기화 한다.

    - Spring Container에 등록되지 않은 bean(xml 설정 파일이나 어노테이션이 없는 bean)은 Spring Container가 spring bean으로써 관리할 수 없기 때문에, 해당 bean을 생성하는 시점에 의존하고 있는 bean이 생성되지 않아도 먼저 생성해주지 않는다.

      => 의존하는 bean이 null 값이 되는 경우가 발생할 수 있다.

- 참고 : https://sehun-kim.github.io/sehun/springbean-lifecycle/

  

## IoC(Inversion of Control)

#### Spring Container

- Spring Container는 개발자가 작성한 코드의 처리과정을 위임받아 독립적으로 처리하는 컨테이너이다.

- 사용하는 이유

  - 이전까지는 클래스 내에서 다른 객체를 사용하고 싶을 때 직접 new 연산자로 객체를 생성하고, getter/ setter로 값을 관리하여야 했다.

  - 이는 높은 의존성과 결합도를 가지게 된다.

    - 프로그램 내에서 서로 생성하고 참조하는 객체가 많아지게 된다.
    - 즉, 참조되는 객체의 구현이 바뀌게 되면 그 객체를 참조하고 있는 객체에서의 생성과 호출(사용)도 바뀌어야 한다. => 의존성이 높다.

  - OOP는 낮은 의존성과 높은 캡슐화를 지향하기 때문에 의존성을 낮추기 위해 Spring Container를 사용한다.

    

## Servlet

#### Servlet Container

![img](https://i.imgur.com/alHA0zr.jpg)

- servlet container는 servlet의 생성부터 소멸까지의 life cycle을 관리한다.

- 클라이언트의 요청이 들어올 때마다 새로운 자바 스레드를 생성한다.(thread per request)
- 웹 서버와 통신하기 위해 개발자가 직접 소켓을 생성하고, 특정 포트를 listening 하고 stream을 생성하는 등의 구현을 하지 않아도 된다.
- 대표적인 servlet container : tomcat
- Servlet 동작과정
  - 사용자가 특정 url을 클릭하면 클라이언트 서버는 HTTP Request를 servlet container에 보낸다.
  - servlet container는 HttpServletRequest, HttpServletResponse 두 객체를 생성한다.
  - 요청 URL을 분석하여 해당 url에 매핑되는 서블릿을 찾는다.
  - 해당하는 서블릿의 service() 메소드를 호출하여 요청 메소드에 따라 doGet() 또는 doPost() 메소드가 호출된다.
  - doGet() / doPost() 메소드 내에서 동적 페이지를 생성 후 HttpServletResponse 객체에 응답을 보낸다.
  - 응답이 완료되면 HttpServletRequest, HttpServletResponse 객체를 소멸시킨다.



#### Servlet과 Thread

- 사용자의 하나의 요청에 대해 하나의 새로운 스레드가 생성되고, 서블릿이 수행된다.

- 즉, 서블릿은 스레드 안에서 작동한다.

- Servlet 3 이상부터 스레드 사용 방식을 `thread per request` 로 관리한다.

  - thread가 매 클라이언트의 접속마다 할당되는 것이 아니라, 일정 크기의 thead pool 안에서 제공되는 thread를 클라이언트 요청마다 재사용하는 것이다.

    - thread pool은 스레드를 무한정으로 생성하다가 제한된 운영체제의 자원에 의해 스레드 고갈 현상이 발생하는 것을 막는다.

    - 즉, 일정 개수 만큼의 스레드를 미리 만들어놓고, 클라이언트의 요청이 들어올 때마다 무한 재사용한다. 

      => 스레드를 운영체제에 반납하지 않고 계속 재사용하기 때문에 스레드 생성 비용도 줄일 수 있다.

  - 한 클라이언트의 요청에 대해서 한 스레드가 요청-응답 과정을 처리한다.

    - 클라이언트의 요청을 처리하는 스레드에서 클라이언트에 전송할 응답을 생성한다.
    - 즉, 여러 클라이언트 요청에 대해서 멀티 스레드로 동작하지만, 각 스레드는 blocking 되어있어 각 클라이언트의 작업은 synchronous하게 수행된다.
    - 하나의 서버에 대해서 동시 접속자가 많아 서블릿의 동시호출이 많이 발생하고, 서블릿의 수행 속도가 느려지게 되면 thread pool의 모든 thread가 소비되어 다른 접속자들이 더이상 스레드를 사용할 수 없게되는 문제점이 생긴다.

- 비동기 서블릿의 사용

  - 일반적인 웹에서는 요청을 보내고 응답을 받으면 서버와의 연결을 종료시킨다.

    - 그러나, 채팅 프로그램 같은 경우 클라이언트와 서버가 연결을 계속 유지한 채 server push가 이루어져야 한다.
    - thread pool의 스레드는 한정되어 있기 때문에 일부 클라이언트가 연결을 유지하면서 스레드를 모두 사용하면 다른 클라이언트들에게 서비스를 제공할 수 없게 된다.

  - 비동기 서블릿은 클라이언트에 대한 응답을 별도 스레드로 처리하도록 한다.

    - 서블릿의 doGet() / doPost() 메소드 내에서 새로운 스레드를 생성하여 응답을 수행하도록 한다.

      - 비동기로 요청을 처리하기 위한 AsyncContext 객체를 HttpServletRequest 객체의 startAsync() 메소드를 이용하여 생성한다.

      - 서블릿이 종료되더라도 AsyncContext 객체를 활용하여 HttpServletReponse 객체를 생성할 수 있고, 응답을 처리할 수 있다.

      - AsyncContext 객체는 스레드가 아니다. 

        - 서버에서 클라이언트에 언제든지 server push 할 수 있도록 응답 객체를 가지고 있을 뿐이다.

          (하나의 스레드(채팅방)에 여러개의 AsyncContext 객체(채팅 참여 클라이언트)를 포함시켜 동기화시킬 수 있다.)

        - 클라이언트에 대한 응답이 완료되거나 타임아웃이 발생하면 complete() 메소드로 클라이언트와의 연결을 종료하게 된다.

  ```java
  @WebServlet(urlPatterns = "/hello", asyncSupported = true)
  public class AsyncHelloWorldServlet extends HttpServlet {
  
      private Logger logger = Logger.getLogger(getClass());
      
      @Override
      protected void doGet(HttpServletRequest req, HttpServletResponse res)
              throws ServletException, IOException {
          final AsyncContext asyncContext = req.startAsync();
  
          new Thread(new Runnable() {
              @Override
              public void run() {
                  try {
                      Thread.sleep(5000);
                  } catch (InterruptedException e) {}
                  
                  HttpServletResponse response = 
                      (HttpServletResponse) asyncContext.getResponse();
  
                  response.setContentType("text/plain");
              	response.setCharacterEncoding("UTF-8");
  
                  try {
                      response.getWriter().println("HELLO");
                  } catch (IOException e) {
                      e.printStackTrace();
                  }
  
                  logger.info("complete response");
                  asyncContext.complete();
              }
          }).start();
        
          logger.info("doGet return");
      }
  }
  ```

- 참고 

  -  https://javacan.tistory.com/entry/Servlet-3-Async

  - [https://github.com/dalcomlab/waffle-java/wiki/%5B%EC%84%9C%EB%B8%94%EB%A6%BF%5D%EB%B9%84%EB%8F%99%EA%B8%B0-%EC%84%9C%EB%B8%94%EB%A6%BF-%EB%8F%99%EC%9E%91-%EB%B0%A9%EC%8B%9D%EC%97%90-%EB%8C%80%ED%95%9C-%EC%A0%95%EB%A6%AC-%E2%80%93--%231](https://github.com/dalcomlab/waffle-java/wiki/[서블릿]비동기-서블릿-동작-방식에-대한-정리-–--%231)

  

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

#### Servlet과 Spring MVC

- Servlet은 J2EE 프레임워크의 일부이며, 모든 JAVA 어플리케이션 서버(tomcat 등)는 서블릿을 실행하기 위해 빌드된다.

  - Servlet은 Web Server의 요청을 동적으로 처리 가능한 자바 클래스이다.
  - 하나의 Servlet 클래스는 하나의 URL과 매핑된다.
    - 하나의 클래스에서 여러 URL을 처리하기 위해서는 파싱하여 분리하는 복잡한 방법을 사용해야 한다.
  - 미리 패키징 되어있기 때문에 Servlet.jar 가 필요하지 않다.

- Spring MVC는 MVC 패턴을 적용하여 좀 더 쉽게 개발을 하기 위해 사용되는 Servlet 위에 구축된 라이브러리이다.

  (Spring에서 제공하는 다양한 모듈 중 하나)
  - Form 데이터 parameter, 컨트롤러 메서드의 parameter 매핑, 바이너리 form 제출, bean 변환 등을 쉽게 처리할 수 있는 기능들을 제공한다.
  - 하나의 클래스에서 여러 URL과 매핑되는 여러 메소드를 관리할 수 있다.
  - Spring 컨트롤러를 실행하려면 필요한 jar 파일을 패키징 해야한다.

- 즉, Servlet은 Java Application의 Low 레벨에서 동작하고, Spring MVC는 그것 보다는 High 레벨에서 동작한다고 할 수 있다.

  

#### Spring Container

- 어플리케이션의 Bean들의 생명주기를 관리하는 컨테이너

  => 개발자가 직접 인터페이스 호출하거나 new 연산자로 객체 생성 등을 통해 의존성을 만들지 않아도 된다.

- bean을 관리하기 위해 DI(Dependency Injection)를 사용한다.



#### 웹 어플리케이션 동작 원리

![img](https://i.imgur.com/PlDF42i.png)

- Dispatcher servlet : 서블릿 컨테이너에서 HTTP 프로토콜을 통해 들어오는 모든 클라이언트의 요청을 presentation 계층의 제일 앞에서 중앙집중식으로 처리해주는 Front Controller 역할
  
  - `servlet-context.xml` 을 로딩하여 Controller bean들을 포함하는 Spring Container를 생성한다.
  - 기존의 servlet
    - web.xml에 servlet과 url 패턴을 등록하고 매핑하는 과정이 필요하다.
    - 즉, url 당 새로운 servlet을 생성하여 요청을 처리해야 했다.
- Front Controller
  
  - 하나의 Servlet에서 모든 요청을 받아들여 적절한 controller로 요청을 위임해준다.
  
- ContextLoaderListener 

  - DAO, DTO, Service 등 controller가 공유하는 bean들을 포함하는 Spring Container를 생성한다.

  - bean에 대한 설정 파일 `root-context.xml` 을 로딩 후 생성한다.

  - DispatcherServlet에 의해 생성된 bean(controller)은 ContextLoaderListener에 의해 생성된 bean을 참조할 수 있다.

    ![img](https://gmlwjd9405.github.io/images/web/springmvc-contextLoadListener.png)

- 참고 

  - https://minwan1.github.io/2017/10/08/2017-10-08-Spring-Container,Servlet-Container/

  - https://gmlwjd9405.github.io/2018/10/29/web-application-structure.html



## Error Handling

#### BasicErrorController

- Spring boot에서는 기본적인 에러 처리를 하는 BasicErrorController를 제공한다.
- 요청한 HTTP의 Accept 헤더에 text/html 이 포함된 경우엔 html 뷰를 반환하고, 그 외는 JSON 객체를 반환한다.
- 일반적인 spring boot의 페이지 404 에러시 나오는 whitelabel error page는 BasicErrorController에서 반환한 html 뷰이다.

```java
// text/html가 포함된 헤더가 있는 요청에는 뷰를 반환
@RequestMapping(produces = {"text/html"})
public ModelAndView errorHtml(HttpServletRequest request, HttpServletResponse response) {
    HttpStatus status = this.getStatus(request);
    Map<String, Object> model = Collections.unmodifiableMap(this.getErrorAttributes(request, this.isIncludeStackTrace(request, MediaType.TEXT_HTML)));
    response.setStatus(status.value());
    ModelAndView modelAndView = this.resolveErrorView(request, response, status, model);
    return modelAndView != null ? modelAndView : new ModelAndView("error", model);
}

// 그 외에는 json 객체를 반환
@RequestMapping
  public ResponseEntity<Map<String, Object>> error(HttpServletRequest request) {
      Map<String, Object> body = this.getErrorAttributes(request, this.isIncludeStackTrace(request, MediaType.ALL));
      HttpStatus status = this.getStatus(request);
      return new ResponseEntity(body, status);
  }
```



#### @ExceptionHandler

- @Controller 어노테이션으로 선언된 컨트롤러 내의 메소드에서 발생한 Exception을 처리한다.

  ```java
  @Controller public class SimpleController { 
      // ... 
      @ExceptionHandler 
      public ResponseEntity<String> handle(Exception ex) { 
          // ... 
      } 
  }
  ```

- Exception 마다 처리 방식이 다를 경우, @ExceptionHandler에 대상 Exception 목록을 지정하여 각각 처리할 수 있다.

  ```java
  @ExceptionHandler({FileSystemException.class, RemoteException.class})
  ```



#### @ControllerAdvice

- @Controller에 정의된 @ExceptionHandler는 해당 컨트롤러에서만 동작한다.

- 모든 컨트롤러에서 공통적으로 처리할 에러가 있을 경우

  - @ControllerAdvice 어노테이션으로 선언된 컨트롤러에서 @ExceptionHandler 를 선언하여 모든 컨트롤러에 대해 발생한 전역 에러 처리를 할 수 있다.

  ```java
  @Controller 
  @ControllerAdvice 
  public class GlobalExceptionController { 
      // ... 
      @ExceptionHandler 
      public ResponseEntity<String> handle(IOException ex) { 
          // ... 
      } 
  }
  ```

- 컨트롤러 대상을 좁히고 싶을 경우 어노테이션, 패키지, 클래스 기준으로 지정해서 사용할 수 있다.

  ```java
  @ControllerAdvice(annotations=RestController.class)
  @ControllerAdvice("com.hs.reivew.controller")
  @ControllerAdvice(assignableTypes = {ControllerInterface.class})
  ```

  

## Filter VS Interceptor

![img](https://t1.daumcdn.net/cfile/tistory/9983FB455BB4E5D30C)

#### Filter

- Dispatcher Servlet의 앞단에서 클라이언트의 요청과 응답을 처리하는 역할

- J2EE 표준 스펙에 정의되어있는 기능

  - 즉, Servlet Container에 의해 동작이 제어되는 Java class이다.
  - Spring Framework와는 무관하게 지정된 자원에 대해서 동작한다.

- 주로 전역적으로 무언가 처리해야하는 로직을 구현할 때 사용한다.

  - ex) 인코딩, 보안 처리(XSS)

- Filter chain을 가지고 순서대로 동작한다.

  ```java
  public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
      /**
          filtering 로직 구현 
      */
  
      // 해당 필터의 처리 결과를 다음 필터로 넘겨주는 역할
      // 다음 필터가 없다면 서블릿으로 전달
      filterChain.doFilter(servletRequest, servletResponse);
  }
  ```

- web.xml 또는 Java configuration을 이용해 구현한다.

  

#### Interceptor

- Spring Context 내에서 HttpRequest와 HttpResponse를 처리하는 역할
  - Dispatcher Servlet에서 Controller로 요청이 넘어가기 전 처리된다.
  - Spring 내의 모든 bean에 접근할 수 있다.
- 인증, 권한, 업로드 파일 처리 등의 디테일한 로직을 구현할 때 사용한다.
- ServletContext.xml 또는 Java configuration을 이용해 구현한다.