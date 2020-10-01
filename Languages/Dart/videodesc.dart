import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:inosens/views/profile/profile.dart';
import '../views/profile/userProfile.dart';

Widget videoDesc(
    BuildContext context, DocumentSnapshot userData, DocumentSnapshot videoDesc) {
      
  return Container(
    padding: EdgeInsets.only(left: 16, bottom: 60),
    child: Column(
      mainAxisAlignment: MainAxisAlignment.end,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: <Widget>[
        Padding(
          padding: EdgeInsets.only(top: 7, bottom: 7),
          child: InkWell(
            onTap: () {
              print("Username");
              //* If userlogedin the navigate to personal profile else navigate to usersprofile
              //* Here we will navigate to otherusers profile page first
              // Navigator.push(
              //     context,
              //     MaterialPageRoute(
              //       builder: (c) => Profile(userData),
              //     ));

              Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (c) => UserProfile(),
                  ));
            },
            child: userData.data != null ?Text(
              "@${userData.data["username"]}",
              style: TextStyle(
                  fontSize: 14,
                  color: Colors.white,
                  fontWeight: FontWeight.w500),
            ):Text('Unknown'),
          ),
        ),
        Padding(
          padding: EdgeInsets.only(top: 4, bottom: 7),
          child: Text(videoDesc.data["postTitle"],
              style: TextStyle(
                  color: Colors.white,
                  fontSize: 14,
                  fontWeight: FontWeight.w300)),
        ),
         Row(
          children: <Widget>[
            Icon(
               Icons.music_note,
               size: 19,
               color: Colors.white,
             ),
             Text(
               videoDesc.data["postTags"].toString(),
              style: TextStyle(
                   color: Colors.white,
                   fontSize: 14,
                   fontWeight: FontWeight.w300),
            )
           ],
         ),
      ],
    ),
  );
}
