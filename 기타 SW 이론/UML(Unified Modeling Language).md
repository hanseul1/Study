# UML(Unified Modeling Language)

## UML 다이어그램 

#### Structure Diagram

- 클래스 다이어그램
- 객체 다이어그램
- 컴포넌트 다이어그램
- 패키지 다이어그램

#### Behavior Diagram

- state machine diagram
- use case diagram



## 클래스 관계

#### association (연관관계)

- 실선이나 화살표로 표현

- 클래스들이 개념상 서로 연결되었음을 의미한다.

- 한 클래스가 다른 클래스에서 제공하는 기능을 사용하는 상황일 때 표시

  - 클래스의 속성(멤버 필드)에서 참조할 때

    <img src="https://gmlwjd9405.github.io/images/class-diagram/bi-directional.png" alt="img" style="zoom: 33%;" />



#### Generalization (일반화 관계)

- 속이 빈 화살표로 표현

- 한 클래스가 다른 클래스를 포함하는 상위개념, 즉 상속 관계일 때 표시

- 부모클래스에 명시된 공통적인 멤버필드나 메서드는 자식클래스에 중복하여 쓰지 않아도된다.

  - 자식클래스에서 재정의 했을 경우에는 명시

  <img src="https://gmlwjd9405.github.io/images/class-diagram/generalization-class.png" alt="img" style="zoom: 33%;" />



#### Aggregation (집약 관계)

- 속이 빈 다이아몬드로 표현
- 집합 관계의 일종으로, 하나의 클래스가 다른 클래스를 포함할 때 표시
  - 포함된 클래스의 객체를 다른 클래스와 공유할 수 있다.
  - 전체 객체의 생성자에서 참조값을 인자로 받아 필드를 세팅한 경우가 이에 속한다.
  - 전체 객체의 라이프타임과 부분 객체의 라이프타임은 독립적이다.



#### Composition (합성 관계)

- 속이 찬 다이아몬드로 표현
- 집합 관계의 일종으로, 하나의 클래스가 다른 클래스에 속할 때 표시
  - 포함된 클래스의 객체를 다른 클래스와 공유할 수 없다.
  - 전체 객체의 생성자에서 부분 객체를 직접 생성하는 경우가 이에 속한다.
  - 전체 객체의 라이프타임과 부분 객체의 라이프타임은 의존적이다.

<img src="https://gmlwjd9405.github.io/images/class-diagram/set-uml-example.png" alt="img" style="zoom:33%;" />



#### Dependency (의존 관계)

- 점선 화살표로 표현

- 하나의 클래스가 다른 클래스에서 제공하는 기능을 사용할 때 표시

  - 메소드의 인자로 참조값이 사용될 때
  - 메소드 내부의 지역 객체로 참조될 때

  <img src="https://gmlwjd9405.github.io/images/class-diagram/dependency-uml.png" alt="img" style="zoom:33%;" />



#### Realization (실체화 관계)

- 빈 삼각형과 점선으로 표현

- 인터페이스와 인터페이스의 명세를 구현한 클래스 사이의 관계를 표시

  <img src="https://gmlwjd9405.github.io/images/class-diagram/interface-uml.png" alt="img" style="zoom:33%;" />