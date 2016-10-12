//
// Created by clj on 2016/10/12.
//

#ifndef DESIGNPATTERN_PROTOTYPE_HPP
#define DESIGNPATTERN_PROTOTYPE_HPP

#include <iostream>
#include <string.h>

using namespace std;

namespace prototype {

    class AbstractMatrix {
    public:
        AbstractMatrix() {}

        virtual ~AbstractMatrix(){};

        virtual AbstractMatrix *deep_clone() = 0;
        virtual AbstractMatrix *shallow_clone() = 0;


    private:
        int _row;
        int _col;
        float *_data;

    };


    class MatrixRowLead : public AbstractMatrix {

    public:
        MatrixRowLead() : _row(0), _col(0), _data(NULL) {
            cout << "Init MatrixRowLead" << endl;
        }

        MatrixRowLead(int row, int col) : _row(row), _col(col), _data(NULL) {
            _data = new float[row * col];
            cout << "Init MatrixRowLead" << endl;
        }

        virtual ~MatrixRowLead(){

            if(_data != NULL){

                try {
//                    delete[] _data;
                }catch (exception &e){
                        // do nothing
                }
                _data = NULL;
            }
            cout << "destroy MatrixRowLead" << endl;
        }

        virtual MatrixRowLead *deep_clone(){
            MatrixRowLead *m = new MatrixRowLead;
            m->_col = this->_col;
            m->_row = this->_row;
            m->_data = new float[m->_row * m->_col];
            memcpy(m->_data, this->_data, sizeof(float) * m->_col * m->_row);

            return m;
        }

        virtual MatrixRowLead *shallow_clone(){
            MatrixRowLead *m = new MatrixRowLead;
            m->_col = this->_col;
            m->_row = this->_row;
            m->_data = this->_data;  //when original class free _data and set it as NULL, _data in shallow clone class
                                      // is still not NULL, so the deconstruction function will fail.
            return m;
        }

    private:
        int _row;
        int _col;
        float *_data;

    };


    class MatrixColLead : public AbstractMatrix {

    public:
        MatrixColLead() : _row(0), _col(0), _data(NULL) {
            cout << "Init MatrixColLead" << endl;
        }

        MatrixColLead(int row, int col) : _row(row), _col(col), _data(NULL) {
            _data = new float[row * col];
            cout << "Init MatrixColLead" << endl;
        }

        virtual ~MatrixColLead(){

            try {
                if (_data != NULL) {
//                    delete[] _data;
                }
            }catch(exception &e){
                // do nothing
            }
            _data = NULL;
            cout << "destroy MatrixColLead" << endl;
        }

        virtual MatrixColLead *deep_clone(){
            MatrixColLead *m = new MatrixColLead;
            m->_col = this->_col;
            m->_row = this->_row;
            m->_data = new float[m->_row * m->_col];
            memcpy(m->_data, this->_data, sizeof(float) * m->_col * m->_row);

            return m;
        }

        virtual MatrixColLead *shallow_clone(){
            MatrixColLead *m = new MatrixColLead;
            m->_col = this->_col;
            m->_row = this->_row;
            m->_data = this->_data;

            return m;
        }

    private:
        int _row;
        int _col;
        float *_data;

    };

}  // end namespace prototype


#endif //DESIGNPATTERN_PROTOTYPE_HPP
