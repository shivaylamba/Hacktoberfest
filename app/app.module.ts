import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { UploadDataComponent } from './upload-data/upload-data.component';
import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import {provideStorage ,getStorage} from '@angular/fire/storage';
import { provideFirestore , getFirestore } from '@angular/fire/firestore';
import { AngularFireModule } from '@angular/fire/compat';
import { environment } from 'src/environments/environment';
import { FormsModule } from '@angular/forms';

@NgModule({
  declarations: [
    AppComponent,
    UploadDataComponent
  ],
  imports: [
    FormsModule,
    BrowserModule,
    provideFirebaseApp(()=>initializeApp(environment.firebaseConfig)),
    AngularFireModule.initializeApp(environment.firebaseConfig),
    provideFirestore(()=>getFirestore()),
    provideStorage(()=>getStorage())
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
