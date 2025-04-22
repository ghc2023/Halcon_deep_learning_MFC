
#ifndef __HALCON_PUBLIC_H__
#define __HALCON_PUBLIC_H__

#include "Halconcpp.h"
#include "HDevThread.h"
// #include <string>
// using namespace std;
using namespace HalconCpp;

#ifdef __cplusplus
extern "C"
{
#endif



//分类-预处理参数;
typedef struct _CLASS_PREPRO_//分类-预处理参数;
{
	//读图;
	//HTuple hv_label; //
	//HTuple hv_SubFile; //
	//HTuple hv_ImageBaseFolder;//有选择性的类子文件;
	//HTuple hv_RawImageFolder;//完成路径，路径下所有文件为训练文件;
	//HTuple hv_ModelFileName;
	//HTuple hv_AllDataSaveDir;


	HTuple hv_LabelSource ;//类名标签不同方式//* LabelSource用于读取数据集。;//'last_folder'最后文件夹名为类名标签;//'file_name'文件名最为类名标签;//'file_name_remove_index'文件名除去后面的序列之后最为类名标签;
	HTuple hv_Class_DLDataset ;
	HTuple  hv_TrainingValidationPercent;
	HTuple  hv_ImagePreprocessFeatures ;
// 	HTuple  hv_ImageWidth ;
// 	HTuple  hv_ImageHeight ;
// 	HTuple  hv_ImageChannels ;
// 	HTuple  hv_Domainhandling ;
// 	HTuple  hv_NormalizationType ;
	HTuple  hv_DLDatasetFileName ;//图像字典路径;
	HTuple  hv_DataDirectory ;//图像字典;
	HTuple  hv_PreprocessParamFile ;//预处理参数字典路径;
	HTuple  hv_DLPreprocessParam ;//预处理参数字典;
	HTuple  hv_Is_overwrite_files ;
	HTuple  hv_constant_values_mean_values_normalization ;
	HTuple  hv_constant_values_deviation_values_normalization ;
	HTuple  hv_ClassNames ;
	HTuple  hv_ClassIDs ;

}CLASS_PREPRO_S;// 分类-预处理;


//分类-训练参数;
typedef struct _CLASS_Train_
{
	//分类-训练参数;
	HTuple  hv_NumEpochs;
	HTuple  hv_BatchSize;
	HTuple  hv_Momentum;
	HTuple  hv_WeightPrior;
	HTuple  hv_InitialLearningRate;
	HTuple  hv_Augmenttation_Percentage;
	HTuple  hv_ChangeLearningRateEpochs;
	HTuple  hv_ChangeLearningRate;
	HTuple  hv_EnableDiasplay;
	HTuple  hv_RandomSeed;
	HTuple  hv_SelectePercentaheTrainSamples;
	HTuple  hv_update_images_interval_epochs;
	HTuple  hv_change_plot_interval_seconds;
	HTuple  hv_update_interval_seconds;
	HTuple  hv_EvaluationIntervalEpochs;
	HTuple  hv_BestModelBaseName;
	HTuple  hv_FinalModelBaseName;
	HTuple  hv_Augmentation_Method;
	HTuple  hv_Augmentation_Value;

	HTuple  hv_TrainSetParam;
	
	HTuple  hv_DispaySetParam;
	
	HTuple hv_ClassBestFinaModelBaseNameSavePath;

	HTuple hv_DLModelHandle;

	HTuple hv_TrainResults;
	HTuple hv_TrainInfos;
	HTuple hv_EvaluationInfos;


}CLASS_Train_S;




#ifdef __cplusplus
}
#endif
#endif // __HALCON_PUBLIC_H__