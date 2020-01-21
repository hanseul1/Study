# SW 디자인 패턴

## GoF 패턴

1. 생성(Creational) 패턴

   \- `Factory `

   \- `Singleton `

   \- `Prototype `

 

2. 구조(Structural) 패턴

   \- `Adapter`

 

3. 행위(Behavioral) 패턴

   \- `Observer`

   \- `Strategy`

   \- `Templete`

 

#### **Strategy 패턴**

\- 행위를 클래스로 캡슐화해 동적으로 행위를 바꿀수 있게 해주는 패턴

\- 같은 문제를 해결하는 여러 알고리즘이 클래스별로 캡슐화 되어있음

 => 즉, 전략을 쉽게 바꿀 수 있도록 해줌

 



![img](https://k.kakaocdn.net/dn/cyjDkf/btqzqUZbxQ6/cKvnrDRKYFE0eb1FlZsoa1/img.png)



\- Strategy : 외부에서 해당 알고리즘을 동일한 방식으로 호출할 수 있도록 명시하는 인터페이스 역할

\- ConcreteStrategy : 실제 문제 해결을 위한 알고리즘을 구현한 클래스

\- Context : Strategy 패턴을 이용하는 역할

 

#### **Singleton 패턴**

\- 해당 클래스의 객체를 하나만 생성하도록 하여, 생성된 객체를 어디서든 참조할 수 있도록 하는 패턴

\- getInstance() 메소드를 통해 외부에 생성된 객체를 반환하는 역할을 수행한다.

 => 모든 클라이언트에게 동일한 객체 반환

 

 

#### **Observer 패턴**

\- 한 객체의 상태 변화에 따라 다른 객체도 연동되도록 일대다 객체 의존관계를 구성하는 패턴

 => 객체의 상태 변화를 관찰하는 Observer(또는 listener)들의 목록을 객체에 attach하여 상태 변화가 있을 때마다 Observer에게 통보하도록 한다.

 



![img](https://k.kakaocdn.net/dn/uOyNb/btqzpH0zk59/zlvAMnYbBRQ58iL6SvWwaK/img.png)



\- 통보 대상 객체 관리를 Subject 클래스와 Observer 인터페이스로 일반화한다.

 => 상태변화를 통보하는 모든 클래스들(ConcreteSubject)이 통보 대상 클래스(ConcreteObserver)들에 대한 의존관계를 가지고 있을 필요가 없다.

 

\- Observer : 데이터의 변경을 통보받는 인터페이스

 -> Subject에서 Observer의 update() 메서드를 호출하면, Observer 인터페이스를 구현한 ConcreteObserver들에게 상태변화를 통보한다.

 

\- ConcreteObserver : Observer 인터페이스의 update() 메소드를 구현함으로써 상태변화를 통보받는다.

 -> 변화된 데이터에 대한 정보는 ConcreteSubject의 getState() 메소드를 호출하여 얻는다.

 

\- Subject : ConcreteObserver 객체를 관리하는 클래스

 -> attach(), detach() 메소드를 통해 Observer 목록을 관리한다.

 

\- ConcreteSubject : 상태 변화(데이터변화)를 통보하는 클래스

 -> setState() 메소드를 통해 데이터를 변경하고, Subject 클래스의 notifyObservers() 메소드를 호출하여 통보한다.

 

\- Observer 패턴 사용시 순환 실행을 막기위한 구현이 필요하다.

 : 이벤트 X 발생시 옵저버 A가 옵저버 B를 갱신하고, 옵저버 B가 다시 옵저버 A를 갱신하는 경우 

 => 다시 옵저버 A는 이벤트 X를 발생시켜 순환이 일어날 수 있다.

 => 한번 이벤트 X가 처리된 후에는 옵저버 A가 다시 이벤트 X를 발생시키지 않도록 처리하는 구현이 필요하다.

 

\- 이용 사례 : 외부에서 발생되는 이벤트(사용자 요청, 입력)에 대한 응답(이벤트 기반 프로그래밍)

​         MVC 패턴에서 모델과 뷰를 연결하기 위해 사용된다.

​         => 모델에서 일어난 변화를 옵저버가 통보받아 뷰의 내용을 바꾸는 역할을 수행하는 경우

 

#### **Factory Method 패턴**

\- 객체 생성을 서브 클래스로 분리하여 처리하도록 캡슐화하는 패턴

 



![img](https://k.kakaocdn.net/dn/bx9C4W/btqzpspeIHe/UYoMeivwpAhw34SwrwxEqK/img.png)



\- Creator는 객체 생성을 위한 인터페이스를 정의

\- ConcreteCreator : 어떤 클래스의 인스턴스를 생성할 지 결정하여 생성

 => Creator의 factoryMethod() 메소드를 구현 -> ConcreteProduct 인스턴스를 생성

```java
public abstract class PizzaStore {  // Creator 역할
    public Pizza orderPizza(String type) {
        Pizza pizza = createPizza(type);
 
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
 
        return pizza;
    }
 
    abstract protected Pizza createPizza(String type);
}
 
public class ChicagoPizzaStore extends PizzaStore {  // ConcreteCreator 역할
    @Override
    protected Pizza createPizza(String type) {  // 타입에 따라 해당하는 인스턴스 생성
        if(type.equals("cheese")) {
            return new ChicagoStyleCheesePizza();
        }
        else if(type.equals("pepperoni")) {
            return new ChicagoStylePepperoniPizza();
        }
        else {
            return null;
        }
    }
}
 
public class Main {
    public static void main(String[] args) {
        PizzaStore nyPizzaStore = new NyPizzaStore();
        PizzaStore chicagoPizzaStore = new ChicagoPizzaStore();
 
        Pizza pizza = nyPizzaStore.orderPizza("cheese");
        System.out.println(pizza.getName() + "피자를 주문 했습니다.");
        System.out.println("===================");
        pizza = chicagoPizzaStore.orderPizza("pepperoni");
        System.out.println(pizza.getName() + "피자를 주문 했습니다.");
    }
}
```

 

 