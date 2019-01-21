# GIT GUIDE FOR TEAM

### 1. Clone repository:

~~~bash
git clone https://<your_user_name>@bitbucket.org/vietanhdev/isd.ict.20181-01.git
~~~

Please replace `<your_user_name>` with your bitbucket username, for example `vietanhdev*

### 2. After clone, create your own branch:

`cd` into Group repository folder, then:

~~~
git checkout <YourName>
~~~

For example `git checkout NguyenVietAnh`.

### 3. Add changes and commit

~~~bash
git add .
git commit -am "<commit message, what was changed?>"
~~~

### 4. Push to your branch

You must merge your branch with remote changes before pushing.

~~~
# Switch to master:
git checkout master
# Sync the lastest changes (from teammates):
git pull
# Switch to your branch:
git checkout <YourName>
# Merge changes from master:
git merge master
~~~