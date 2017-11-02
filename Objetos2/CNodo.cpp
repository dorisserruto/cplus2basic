

CNodo::CNodo (Object * odato){
    oDato = odato->clone();
    pSig = 0;
}

CNodo::CNodo (const CNodo & cnOther){

}

Object * clone(){
    return new CNodo(*this);
}

void CNodo::Print(){

}

void CNodo::Delete_you(){
    if (pSig) pSig->Delete_you();
    delete this;
}
