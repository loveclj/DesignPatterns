//
// Created by lizhifeng on 10/13/16.
//

#include "test.hpp"
#include "../composite/Composite.hpp"

using namespace composite;


void test_composite(){

    Image *img1 = new Image("image1");
    Image *img2 = new Image("image2");
    Image *img3 = new Image("image3");

    Text *txt1 = new Text("text1");
    Text *txt2 = new Text("text2");
    Text *txt3 = new Text("text3");

    Binary *bnr1 = new Binary("Binary1");
    Binary *bnr2 = new Binary("Binary2");
    Binary *bnr3 = new Binary("Binary3");

    Folder *fld1 = new Folder("Folder1");
    Folder *fld2 = new Folder("Folder2");
    Folder *fld3 = new Folder("Folder3");
    Folder *fld4 = new Folder("Folder4");

    fld1->add_file(img1);
    fld1->add_file(txt1);
    fld1->add_file(bnr1);

    fld2->add_file(img2);
    fld2->add_file(txt2);
    fld2->add_file(bnr2);

    fld3->add_file(img3);
    fld3->add_file(txt3);
    fld3->add_file(bnr3);

    fld4->add_file(fld1);
    fld4->add_file(fld2);
    fld4->add_file(fld3);


    fld4->get_child_name();
}