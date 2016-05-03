/*
 * cnn_scorer.h
 *
 *  Created on: May 2, 2016
 *      Author: dkoes
 */

#ifndef SRC_LIB_CNN_SCORER_H_
#define SRC_LIB_CNN_SCORER_H_

#include "caffe/caffe.hpp"
#include "nngridder.h"
#include "model.h"

struct cnn_options {
	//stores options associated with cnn scoring
	std::string cnn_model; //path to model file
	std::string cnn_weights; //weights for model
	std::string cnn_recmap; //optional file specifying receptor atom typing to channel map
	std::string cnn_ligmap; //optional file specifying ligand atom typing to channel map

	bool cnn_scoring; //if true, do cnn_scoring of final pose

	cnn_options(): cnn_scoring(false) {}
};

/* This class evaluates protein-ligand poses according to a provided
 * Caffe convolutional neural net (CNN) model.
 */
class CNNScorer {
	typedef float Dtype;
	caffe::shared_ptr<caffe::Net<Dtype> > net;
	//NNGridder grid;

public:
	CNNScorer() {}
	virtual ~CNNScorer() {}

	CNNScorer(const cnn_options& cnnopts, const model& m);

	bool initialized() const { return net; }

};

#endif /* SRC_LIB_CNN_SCORER_H_ */
