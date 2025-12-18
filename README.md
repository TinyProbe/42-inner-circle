# 🌀 42-inner-circle

<p align="center">
42 Seoul 공통 과제(Inner Circle)의 실제 구현 결과물을 정리한 저장소입니다.
C와 C++를 사용하여 로우레벨 시스템 프로그래밍부터 네트워크 프로그래밍까지의 핵심
역량을 쌓았습니다.
</p>

## 📂 Verified Projects

제공된 서클별 디렉토리 구조를 바탕으로 정리한 완료 과제들입니다.

#### 🟢 Circle 0 ~ 1: Foundation

- libft: C 표준 라이브러리의 주요 함수들을 직접 재구현하여 프로젝트의 기초가 되는 정적 라이브러리를 구축했습니다.

- get_next_line: 파일 디스크립터에서 한 줄씩 데이터를 읽어오는 효율적인 함수를 구현했습니다.

- ft_printf: 가변 인자를 활용하여 다양한 서식을 처리하는 나만의 printf 함수를 만들었습니다.

#### 🟢 Circle 2: Algorithm & Graphics

- push_swap: 두 개의 스택을 이용해 한정된 명령어로 데이터를 정렬하는 최적화 알고리즘을 구현했습니다.

- minitalk: UNIX 시그널을 활용하여 클라이언트와 서버 간의 비트 단위 통신 프로그램을 작성했습니다.

- fractol: MiniLibX 라이브러리를 사용하여 복소수 평면 기반의 프랙탈(Mandelbrot, Julia 등)을 시각화했습니다.

#### 🟢 Circle 3: System Programming

- minishell: Bash의 핵심 기능을 재구현하며 프로세스 제어, 파이프, 리다이렉션 등의 쉘 메커니즘을 학습했습니다.

- philosophers: 뮤텍스(Mutex)를 활용한 스레드 동기화를 통해 '식사하는 철학자 문제'를 해결했습니다.

#### 🟢 Circle 4 ~ 5: C++ OOP & Networking

- cpp_module (00~09): C++98 표준을 기반으로 객체지향 프로그래밍의 핵심(상속, 다형성, 템플릿, STL)을 마스터했습니다.

- ft_irc: C++를 이용하여 IRC(Internet Relay Chat) 프로토콜을 준수하는 멀티 클라이언트 채팅 서버를 구축했습니다.

## 🛠️ 개발 원칙 및 환경

- 언어: C (Norminette 준수), C++ (C++98 표준)

- 빌드: 모든 프로젝트는 Makefile을 포함하며, make 명령어를 통해 자동 빌드가 가능합니다.

- 무결성: valgrind와 fsanitize를 통해 메모리 누수 및 에러를 철저히 검증하였습니다.
