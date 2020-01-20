# Docker

## Docker란?

- container 기반의 오픈소스 가상화 플랫폼

- 다양한 프로그램, 실행 환경을 container로 추상화하고 동일한 인터페이스를 제공하여 프로그램의 배포 및 관리를 단순하게 해준다.

- 즉, Back-end 서버, DB 서버 등의 프로그램을 추상화하여 AWS, Azure 등 다양한 컴퓨터에서 실행 가능하다.

- docker는 virtual machine같이 하나의 온전한 서버를 제공하는 것이 아니라 명령어를 수행하는 환경만 제공하고, 실행할 뿐이다.

- container : 격리된 공간에서 프로세스가 동작하는 기술

  - 하나의 서버에 여러개의 컨테이너를 실행하면 서로 영향을 미치지 않고 독립적으로 실행할 수 있다.

- Image : 컨테이너 실행에 필요한 파일과 설정값 등을 포함하고 있는것

  - 즉, 컨테이너는 이미지를 실행한 상태라고 볼 수 있다.

  - 같은 이미지에서 여러개의 컨테이너를 생성할 수 있고, 컨테이너의 상태가 바뀌더라도 이미지는 변하지 않는다.

  - 이미지는 누구나 만들어서 Docker hub 등에 배포할 수 있다.

    ![Docker image](https://subicura.com/assets/article_images/2017-01-19-docker-guide-for-beginners-1/docker-image.png)

  - Layer 저장방식

    - image는 컨테이너를 실행하기 위한 모든 정보를 가지고 있기 때문에 자주 다운받기에 용량의 부담이 있다.

    - 기존 이미지에 파일이 추가되거나 수정되었을 때 전체 이미지를 다시 다운받기 보다 수정된 파일만 새로운 layer로 구성하여 추가하도록 한다.

    - 즉, 기존 ubuntu 이미지가 A+B+C 레이어로 구성되어있을 때, nginx 이미지를 추가한다면, A+B+C+nginx 집합으로 구성되는 것이다.

      ![Docker Layer](https://subicura.com/assets/article_images/2017-01-19-docker-guide-for-beginners-1/image-layer.png)

- 참고 : https://subicura.com/2017/01/19/docker-guide-for-beginners-1.html

  ​			[https://www.popit.kr/%EA%B0%9C%EB%B0%9C%EC%9E%90%EA%B0%80-%EC%B2%98%EC%9D%8C-docker-%EC%A0%91%ED%95%A0%EB%95%8C-%EC%98%A4%EB%8A%94-%EB%A9%98%EB%B6%95-%EB%AA%87%EA%B0%80%EC%A7%80/](https://www.popit.kr/개발자가-처음-docker-접할때-오는-멘붕-몇가지/)

  

## AWS EC2에 Docker 설치

- ubuntu 환경에 docker 설치

  ```
  curl -s https://get.docker.io/ubuntu/ | sudo sh
  ```

- 설치 확인

  ```
  docker -v
  ```



## MySQL, Spring Boot 이미지 설치

#### MySQL image 설치

- 설치 명령어(관리자 권한으로 실행)

  ```
  docker run --name mysql -p 3306:3306 -e MYSQL_ROOT_PASSWROD=12345 -d mysql
  ```

  - 옵션

    ```
    -d : detached mode(백그라운드 모드)
    -p : host와 container의 port 연결
    -name : 컨테이너 이름 설정
    -e : container 내에서 사용할 환경변수 설정
    ```

  - run 명령어 : 사용할 image가 저장되어 있는지 확인하고, 없다면 다운로드(pull)한 후 container 생성하고 시작한다.

  - 컨테이너에 실행할 명령을 입력하지 않았기 때문에 컨테이너는 생성 후 바로 종료된다.

    (컨테이너는 프로세스이기 때문에 실행중인 프로세스가 없으면 종료된다.)

- 실행 

  ```
  docker exec -it mysql bash
  ```

  - exec 명령어 : 실행중인 컨테이너에 명령어 실행
  - 현재 실행되고 있는 컨테이너 출력하는 명령어 : docker ps
  - Docker가 다운로드한 image 목록 출력하는 명령어 : docker images



#### Spring Boot image 설치

- Spring Starter Project 생성 (Window 환경)

  - Maven 플러그인 추가 - pom.xml

    ```xml
    <plugin>
    	<groupId>com.spotify</groupId>
    	<artifactId>docker-maven-plugin</artifactId>
    	<version>0.2.3</version>
    	<configuration>
    		<imageName>${docker.image.prefix}/${project.artifactId}</imageName>
    		<dockerDirectory>src/main/docker</dockerDirectory>
    		<resources>
    			<resource>
    				<targetPath>/</targetPath>
    			    <directory>${project.build.directory}</directory>
    			    <include>${project.build.finalName}.jar</include>
    			</resource>
    		</resources>
    	</configuration>
    </plugin>
    ```

- Dockerfile.txt 생성 - 프로젝트 root 폴더에 위치

  ```txt
  FROM openjdk:8-jdk-alpine
  ADD target/great-0.0.1-SNAPSHOT.jar app.jar
  ENV JAVA_OPTS=""
  ENTRYPOINT ["java","-jar","/app.jar"]
  ```

- maven build

  - goals : package
  - target 폴더 하위에 jar 파일 생성 확인

- Docker Image 생성

  - docker for window 설치 후 docker 명령어 사용이 가능해야 한다.

  ```
  docker build -t spring-boot -f ./Dockerfile.txt .
  ```

- Docker Image push (Docker hub에 업로드)

  - docker hub 계정 생성

  - docker 로그인

    ```
    docker login
    ```

  - image 태그 지정

    - 생성한 image에 태그를 지정할 수 있다.

      ```
      docker tag spring-boot [id]/spring-boot:0.1
      ```

  - Docker hub에 image 업로드

    ```
    docker push [id]/spring-boot:0.1
    ```

- Docker Image pull(run) (AWS 환경)

  - AWS 인스턴스 포트 개방

    - 보통 spring boot 실행을 8080번 포트로 연결하므로, 8080번 포트를 개방해주어야 한다.

  - pull & run

    ```
    docker run -d -p 8080:8080 [id]/spring-boot:0.1
    ```

    - container 생성과 동시에 실행된다.

  - 실행 확인

    ```
    http://[ec2_ip]:8080
    ```

- 참고  : https://gunju-ko.github.io/spring/docker/2018/12/22/SpringAndDocker.html