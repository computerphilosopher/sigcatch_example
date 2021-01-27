FROM centos:7

ARG GIT_REPO=https://github.com/computerphilosopher/sigcatch_example

RUN yum update -y; \
yum install -y go git; \
git clone $GIT_REPO; \
pushd sigcatch_example; \
go build catch.go 
