FROM centos:7

ARG GIT_REPO=https://github.com/computerphilosopher/sigcatch_example

RUN yum update -y; \
yum install -y gcc git; \
git clone $GIT_REPO; \
gcc -o sigcatch_example/catch.c
