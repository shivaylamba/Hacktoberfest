import { Component, OnInit } from '@angular/core';
import { AngularFireModule } from '@angular/fire/compat';
import{AngularFirestore} from '@angular/fire/compat/firestore';
import { UploadData } from './uploadData';
import { getDownloadURL, ref, Storage, uploadBytesResumable } from '@angular/fire/storage';

@Component({
  selector: 'app-upload-data',
  templateUrl: './upload-data.component.html',
  styleUrls: ['./upload-data.component.css']
})
export class UploadDataComponent implements OnInit {

  movieObj:UploadData= {
    id:'',
    brandName:"",
    productName:"",
    size:"",
    fabric:"",
    img1:'',
    img2:''
  };
  bName:string="";
  pName:string="";
  size:string="";
  fabric:string="";
  img1:string="";
  img2:string="";
  public file1: any={};
  public file: any={};
  UploadProgress1:any='';
  UploadProgress2:any='';
  imgLoading:any="";
  myArray: any[] = [];
  preview1:any="../assets/preview.jpg";
  preview2:any="../assets/preview.jpg";

  constructor(private afs:AngularFirestore,private storage:Storage) { }
   box = document.getElementById("uploadInput");
  ngOnInit(): void {
  }

  chooseFile(event:any)
  {
    this.file = event.target.files[0];
        const reader = new FileReader();
        reader.onload = e => this.preview1 = reader.result;
        reader.readAsDataURL(this.file);
    
  } chooseMainFile(event:any)
  {
    this.file1 = event.target.files[0];
    const reader = new FileReader();
    reader.onload = e => this.preview2 = reader.result;
    reader.readAsDataURL(this.file1);
    
  }
  
  addMovie(uMovie : UploadData)
  {
    uMovie.id = this.afs.createId();
     return this.afs.collection('/MyLibrary').add(uMovie);
  }
  resetdata()
  {
  this.bName="";
  this.pName="";
  this.size="";
  this.fabric="";
  this.img1="";
  this.img2="";
  }
  // uploadMovieData()
  // {
    
  //   if (this.box != null) {
  //     this.box.classList.add('inputField');
  //   }
  // }
}
