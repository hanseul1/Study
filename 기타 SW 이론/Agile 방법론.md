# Agile 방법론

#### 개요

- why agile?

  효율적인 프로젝트의 진행을 위해

  기업의 생존 => 경쟁력 향상(빠른 기술 변화에 대한 빠른 대응)

```
- 커뮤니케이션
- 상호 협력
- 수평적 조직구조
- 자기주도적
- 탐색적 실험
```

- process + tool + resource

  => agile은 process는 가볍게, resource에 집중되어 있음

  (전통적인 개발 방법론은 process에 집중되어 있음) 



#### Agile 기초

- why agile? , burn charts, product backlog & user story, scrum
- low tech + high touch => 쉬운 기술을 많이 사용하자
- Agile 키워드

```
- 협업
- 고객 중심
- 의사소통
- 효율성
- 유연성
- 반복
- 가치제공
```

- why agile?
  - 팀의 생산성 향상
  - 비용 절감
  - 품질 향상
  - 팀의 업무 만족도 향상

- Being Agile : Agile에 대한 철학과 가치를 받아들이고, 문화를 적용하는 것

  Doing Agile : Agile을 위해 Burn charts 등의 툴을 사용하는 것

-  Agile Triangle
  - Cost와 Time은 고정
  - 일의 Scope가 유연함
    - 고객의 요구사항이 바뀌는 대로 변동(우선순위가 바뀜)
    - 가치가 떨어지는 것은 버림

- Agile 적용 사례

  - 라이트형제의 최초 동력 비행 개발
  - '스포티파이'의 온라인 뮤직 서비스(가장 대표적 : squad,tribe, chapter, guild)
  - ING 은행
  - 아마존(피자두판팀 : 약 6~11명 정도의 팀을 운영)
  - SK 이노베이션
  - 삼성(갤럭시 S7)
  - LG 전자, 쿠팡(Scrum+XP), 카카오, 드라마앤컴퍼니(리멤버 앱), 삼성 SDS
  - 오렌지라이프

- Agile 발전 제약사항

  - Agile mindset
  - Agile mania

- manifest for agile software development

  ```
  1. individual and interaction
  2. working software
  3. customer collaboration
  4. responding to change
  ```

- Agile 특징

  ```
  - value driven
  - iterative
  - failing fast
  - welcome change
  ```

- Sprint backlog : 큰 product backlog를 쪼개서 작업

- Scrum process

  - 역할 : owner, team, scrum master
  - 미팅 : sprint planning, sprint review(약 2주마다 고객에게 승인), daily scrum meeting(스탠드 미팅 : burn charts 활용), sprint retrospective
  - 제품 : product backlog(우선순위 지정), sprint backlog(개발 task 중심), finished work

  ![image-20200108112127639](C:\Users\multicampus\AppData\Roaming\Typora\typora-user-images\image-20200108112127639.png)





#### 요구사항 개발

- Waterfall

  ```
  - plan driven
  - predictive life cycle
  - manufacturing area
  ```

- user story 개발

  - user story : 개발자와 제품책임자와의 소통을 위한 요구사항 정의서

  - product backlog에 정의된 기능을 사용자 스토리라고 한다.

  - story point : 사용자 업무량에 대한 추정 기준

    => 하나의 스프린트동안 개발할 목록으로 사용자 스토리와 그에 맞는 작업을 태스크로 정의하는 sprint backlog로 나눔

- Definition of Done(DoD)

  : 고객이 요구하는 요구사항에 대한 결과를 미리 정의하는 단계

    프로젝트 시작 전 먼저 기능에 대해 공유함



#### 산정 및 계획수립

1. 산정 및 계획수립 개요

- scrum

  - 1~4주동안 sprint planning

- XP

  - iteration or release planning

  - 보통 1주

  - user story 기반으로 risk 등을 참고하여 release planning 수립(high-level estimates)

    -> release planning을 iteration 돌려서 작업

- agile 계획은 선행 노력의 정도는 적고 전체기간동안 반복한다.

  => 원래 요구사항이 변경되는 것을 반영하기 위해 노력을 전반에 걸쳐 분산한다.

  ![image-20200108133847995](C:\Users\multicampus\AppData\Roaming\Typora\typora-user-images\image-20200108133847995.png)

- agile planning concepts

  ```
  1. early delivery of business
  2. early reduction of risk
  3. increased visibility
  ```

- kanban : todo / sprint backlog / doing / done 으로 task 나눠서 관리

- Burn up chart : 완료한 일 기준으로 작성하는 차트(시간 지날수록 상승)

  Burn down chart : 남아있는 일 기준으로 작성하는 차트(시간 지날수록 하강)

2. user story 산정 & user story 우선순위 정의

- 피보나치 수열 : 포인트 추정은 피보나치 수열 기반으로 한다.(1+1 =2, 1+2=3, 2+3=5, ....)

  => 숫자 기준은 프로젝트마다 1시간, 2시간, 1일 등 다양할 수 있다.

- 친화추정 : 비슷한 task들끼리 같은 포인트로 추정한다.

- T-shirts sizing : 스토리에 대한 대략적 추정을 수행(S, M, L, XL, XXL, ...)

- planning poker : 팀원들 전체가 동의하여 업무량을 추정하는 방법

  => 다른 사람 영향 받지 않고 자신의 생각 표현 가능, 업무에 대한 깊은 이해 가능, 팀원 간 의견 통합

3. Sprint Duration 결정 & Velocity 산정

   ![image-20200108162027697](C:\Users\multicampus\AppData\Roaming\Typora\typora-user-images\image-20200108162027697.png)

4. Release plan 개발

5. Sprint Goal & Sprint backlog 개발

6. Sprint plan 개발

- product backlog 로부터 진행할 항목 선택
- 담당자 지정, 태스크단위로 계획 수립



#### 실행 및 통제

- 개요

  ```
  - kanban(low tech)
  - burn charts(low tech)
  - daily stand up meeting(high touch)
  - scrum
  - XP
  ```

- Burndown chart 개발 : 팀 진행 상황을 한 눈에 확인할 수 있음

  => 프로젝트 진행 중 변경사항이 많기 때문에 변경하기에 burn up chart가 더 수월함

- 변경 관리

  - Work In Progress(WIP) : Doing을 관리하여 bottleneck이 없도록해야 생산성이 증가할 수 있다.

- Sprint 검토

  - sprint 목표를 달성했는지 확인하는 회의
  - 데모를 진행하고 피드백을 받는 단계(고객에게 신뢰와 피드백을 받는 중요한 단계)
  - 보통 2주마다 진행

- 제품 출시

- Sprint 회고

