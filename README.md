# Hacktoberfest Hello World

<br/>
HacktoberFest Hello World in every language ever.
Just fork it and add a hello world to contribute for hacktober fest and send a Pull Request!

### Get yourself free goodies by just writing a hello world!
Say hi to the world in any language of your choice!


# What is Hacktoberfest?
Hacktoberfest is a program by Digital Ocean and Github, where you can easily win a T-Shirt just by making 5 pull requests in the month of October to any open source projects on Github.

## Steps to follow :scroll:

### 1. Register for Hacktoberfest

###### https://hacktoberfest.digitalocean.com/


### 2. Fork it :fork_and_knife:

You can get your own fork/copy of [Hello-world](https://github.com/piyush97/Hacktoberfest) by using the <kbd><b>Fork</b></kbd></a> button or clicking [this](https://github.com/shivaylamba/Hacktoberfest/).

 [![Fork Button](https://help.github.com/assets/images/help/repository/fork_button.jpg)](https://github.com/shivaylamba/Hacktoberfest)

### 3. Add a Program in any Language you like :rabbit2:
Once you have forked the repo, add your progam in the language folder in 
main branch, if there is no language folder, make one, then add into it.
You can take a look to the [Programming Language List](https://en.wikipedia.org/wiki/List_of_programming_languages) in Wikipedia to create a new one Hacktoberfest !

### 4. Ready, Steady, Go... :turtle: :rabbit2:

Once you have completed these steps, you are ready to start contributing 
by checking our `Help Wanted` issues and creating [pull requests](https://github.com/shivaylamba/Hacktoberfest/pulls).

### 5. Give this Project a Star :star:

If you liked working on this project, please share this project as much 
as you can and star this project to help as many people in opensource as you can.

<br/>

# Steps to Make Changes and contribute using GIT!

###### To make your own local copy of the repository you would like to contribute to, let’s first open up a terminal window.

###### We’ll use the // git clone //  command along with the URL that points to your fork of the repository.

###### This URL will be similar to the URL above, except now it will end with // .git.// In the cloud_haiku example above, the URL will look like this:
https://github.com/your-username/Hacktoberfest.git

###### You can alternatively copy the URL by using the green “Clone or download” button from your repository page that you just forked from the original repository page. Once you click the button, you’ll be able to copy the URL by clicking the binder button next to the URL:


###### Once we have the URL, we’re ready to clone the repository. To do this, we’ll combine the git clone command with the repository URL from the command line in a terminal window:

git clone https://github.com/your-username/Hacktoberfest.git


### 4. Create a New Branch

###### To create your branch, from your terminal window, change your directory so that you are working in the directory of the repository. Be sure to use the actual name of the repository (i.e. Hacktoberfest) to change into that directory.

##### // cd Hacktoberfest //

###### Now, we’ll create our new branch with the git branch command. Make sure you name it descriptively so that others working on the project understand what you are working on.


##### // git branch new-branch //

###### Now that our new branch is created, we can switch to make sure that we are working on that branch by using the git checkout command:

##### // git checkout new-branch //

###### Once you enter the git checkout command, you will receive the following output:

###### // Output: //
##### // Switched to branch 'new-branch' //
 
###### At this point, you can now modify existing files or add new files to the project on your own branch.

#### Make Changes Locally 

###### Once you have modified existing files or added new files to the project, you can add them to your local repository, which you can do with the git add command. Let’s add the -A flag to add all changes that we have made:

##### // git add -A // or // git add . //



###### Next, we’ll want to record the changes that we made to the repository with the git commit command.

###### The commit message is an important aspect of your code contribution; it helps the other contributors fully understand the change you have made, why you made it, and how significant it is. Additionally, commit messages provide a historical record of the changes for the project at large, helping future contributors along the way.




###### If you have a very short message, you can record that with the -m flag and the message in quotes:
###### // Example: // 
##### // git commit -m "Updated Readme.md" //





###### At this point you can use the git push command to push the changes to the current branch of your forked repository:
###### // Example: //
##### // git push --set-upstream origin new-branch //

### 5. Update Local Repository

###### While you are working on a project alongside other contributors, it is important for you to keep your local repository up-to-date with the project as you don’t want to make a pull request for code that will cause conflicts. To keep your local copy of the code base updated, you’ll need to sync changes.

###### We’ll first go over configuring a remote for the fork, then syncing the fork.

### 6. Configure a Remote for the Fork

###### Next, you’ll have to specify a new remote upstream repository for us to sync with the fork. This will be the original repository that you forked from. you’ll have to do this with the git remote add command.

##### // git remote add upstream https://github.com/shivaylamba/Hacktoberfest.git //




###### In this example, // upstream // is the shortname we have supplied for the remote repository since in terms of Git, “upstream” refers to the repository that you cloned from. If you want to add a remote pointer to the repository of a collaborator, you may want to provide that collaborator’s username or a shortened nickname for the shortname.

### 7. Sync the Fork

###### Once you have configured a remote that references the upstream and original repository on GitHub, you are ready to sync your fork of the repository to keep it up-to-date.
###### To sync your fork, from the directory of your local repository in a terminal window, you’ll have to use the // git fetch // command to fetch the branches along with their respective commits from the upstream repository. Since you used the shortname “upstream” to refer to the upstream repository, you’ll have to pass that to the command:

##### // git fetch upstream //

###### Switch to the local master branch of our repository:

##### // git checkout master //

###### You’ll now have to merge any changes that were made in the original repository’s master branch, that you will access through your local upstream/master branch, with your local master branch:

##### // git merge upstream/master //

### 8. Create Pull Request

###### At this point, you are ready to make a pull request to the original repository.

###### You should navigate to your forked repository, and press the “New pull request” button on your left-hand side of the page.

# Hurray!! You just got closer to complete your hacktoberfest challenge.

