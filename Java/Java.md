# Java

## JVM(Java Virtual Machine)

![img](https://k.kakaocdn.net/dn/TQ5Md/btqy1Jy5Y9L/NzJUqAijokDiCaNhwPO5iK/img.png)



#### Method Area(Class Area)

- class 파일의 바이트코드가 로드되는 영역
- 즉, JVM이 읽어 프로그램을 실행할 수 있는 '프로그램의 흐름을 구성하는 바이트코드'가 존재한다.
- class정보(생성자, 메소드, static 변수, 멤버 변수), runtime constant pool 저장

#### Heap Area

- 런타임시 동적으로 메모리를 할당하여 사용하는 영역
- new 연산자로 생성된 객체와 배열을 저장한다.
- 해당 메모리를 참조하는 변수나 필드가 없다면 GC의 대상이 된다.

#### Stack Area

- 각 스레드마다 하나씩 존재하며, 스레드 시작시 할당되는 영역
- 메소드 정보(지역변수, 매개변수 등) 저장
- primitive 타입 변수는 스택 영역에 직접 값을 가지고, reference 타입 변수는 힙 영역이나 메소드 영역의 객체 주소를 가진다.

#### PC Register

- 현재 수행중인 JVM 명령 주소를 가짐

#### Native Method Stack Area

- 자바 외 언어로 작성된 네이티브 코드를 위한 영역
- 즉, JNI(Java Native Interface)를 통해 호출되는 코드를 수행하기 위한 스택

- 참고 : https://hoonmaro.tistory.com/19

## GC(Garbage Collection)

## 객체 지향 프로그래밍의 특징

#### 다형성(Polymorphism)

#### 상속(Inheritance)

#### 추상화(Abstraction)

#### 캡슐화(Encapsulation)

## 객체지향 프로그래밍 설계 5대 원칙(SOLID)

#### Single Responsibility Principle(단일 책임 원칙)

#### Open Closed Principle(개방-폐쇄 원칙)

#### Liskov Substitution Principle(리스코프 치환 원칙)

#### Interface Segregation Principle(인터페이스 분리 원칙)

#### Dependency Inversion Principle(의존 역전 원칙)

- 참고 : https://gmlwjd9405.github.io/2018/07/05/oop-solid.html

## Method Overriding & Overloading

#### Method Overriding  규칙

- Exception throws 규칙
  - 상위 클래스에서 throws한 예외의 범위를 넘지 않아야 한다.
    - 상위 클래스에서 throws한 예외의 Sub Exception을 던지거나 같은 Exception을 던진다.
    - 예외를 throws하지 않는다.
    - Runtime Exception을 던진다.(상위 클래스와 관계 없음)
- Access Modifier 규칙
  - 상위 클래스의 Access Modifier와 같거나 더 넓은 범위의 Access Modifier로 선언해야 한다.
- Method 이름, Return type, Parameter는 같아야 한다.

#### Method Overloading 규칙

- method 이름은 같아야 한다.
- parameter 규칙
  - 개수 또는 데이터 타입이 달라야 한다.

- 그 외는 상관없음

## String

#### String

- 새로운 값을 할당할 때마다 새로운 객체가 생성된다.

- 저장되는 문자열은 내부에서 private final char[] 형태로 저장된다.

  => 초기 값 변경 불가

#### StringBuilder

- 메모리에 append하는 방식으로, 문자열 객체를 직접 생성하지 않는다.
- 비동기 처리

#### StringBuffer

- StringBuilder를 확장하여 동기 처리가 가능하게한다.
- 즉, multi thread 환경에서 thread-safe하게 관리 가능하다.

## Wrapper Class

## Modifier

#### Access Modifier

- public : 프로젝트 내 모든 클래스에서 접근 가능
- protected : 같은 패키지, 상속받은 자식 클래스에서 접근 가능
- (default) : 같은 패키지 내의 클래스에서 접근 가능
- private : 해당 클래스 내에서만 접근 가능

#### Usage Modifier

- static : 멤버 변수, 멤버 method, 멤버 nested class
  - static variable : 객체 생성 없이 사용 가능 => 해당 클래스를 인스턴스화한 객체들 간의 공용변수로 사용
  - static method 
    - 객체 생성 없이 사용 가능
    - static variable과 method만 사용 가능하다.
    - 인스턴스가 생성되지 않았을 때도 호출 가능하기 때문에 this, super 변수는 사용 불가하다.
    - overriding 불가
- final : class, variable, method
  - final class : 상속 받을 수 없음
  - final variable : 상수
  - final method : overriding 불가
- abstract : class, method

## Interface

#### 컴파일 시 추가되는 Modifier

- variable : public static final
  - 인터페이스에는 상수만 정의될 수 있다.(객체 생성이 불가능하기 때문)
- method : public abstract
  - 인터페이스의 모든 method는 abstract method이다.
  - 구현 클래스에서 overriding시 메소드는 항상 public 제한자를 가져야 한다.

- 추상클래스와 인터페이스의 차이점
  - 서로 다른 목적을 가지고 있다.
    - 추상클래스는 추상메서드를 자식 클래스가 구체화하여 그 기능을 확장하는데 목적이 있다.
    - 인터페이스는 서로 관련이 없는 클래스에서 공통적으로 사용하는 방식이 필요하지만 각각 구현할 필요가 있을 경우에 사용한다.
  - 추상클래스는 `is a kind of` 인터페이스는 `can do this`
  - 추상클래스는 단일 상속, 인터페이스는 다중 상속 가능

## Collection

![img](https://github.com/WeareSoft/tech-interview/raw/master/contents/images/java-collections-framework.png)

#### Set

- 객체를 순서 없이 저장하고, 같은 데이터는 무시된다.(equals(), hashCode() 비교)
- HashSet : Set을 구현한 클래스
  - hash algorithm을 사용하여 검색 속도가 매우 빠르다.
  - 저장 순서를 유지하지 않음
- LinkedHashSet : 저장 순서를 유지하는 HashSet 클래스
- TreeSet : SortedSet을 구현한 클래스
  - binary search tree 형태로 객체 저장
  - Comparator의 구현으로 sort 방법 지정 가능

#### List

- 객체를 순서대로 저장하고, 인덱스를 부여한다.

- 중복된 데이터도 새로운 인덱스를 부여하여 저장한다.

- ArrayList

  - 단방향 포인터 구조

  - 각 데이터에 대한 인덱스를 가지고 있어 각 데이터의 접근이 빠름

  - 데이터 삽입, 삭제시 다소 느림

    (해당 데이터 이후 모든 데이터가 복사되어야 하기 때문)

- LinkedList

  - 양방향 포인터 구조

  - 데이터 삽입, 삭제시 앞뒤 포인터만 연결해 주면 되므로 속도가 빠름

  - 데이터 검색시 다소 느림

    (처음부터 노드를 순회해야 하기 때문)

#### Map

- 객체 저장, 관리 시에 검색을 보다 쉽게 하기 위해 구현된 인터페이스
- 객체를 Key와 Value로 구분하여 관리한다.
- Key를 통해 검색과 삭제를 쉽게 할 수 있다.

- HashMap
  - 내부 hash function을 통해 인덱스 계산
  - 저장 순서를 유지하지 않음
  - Key와 Value에 null값을 허용한다.

- LinkedHashMap
  - HashMap을 상속받은 클래스
  - 저장 순서를 유지하며 LinkedList로 저장한다.
- TreeMap
  - Red-Black Tree 형태로 객체 저장
  - Key값 기준 오름차순으로 정렬
  - Key값에 대한 Comparator 구현으로 정렬 방법 지정 가능



## Thread

#### Process VS Thread

