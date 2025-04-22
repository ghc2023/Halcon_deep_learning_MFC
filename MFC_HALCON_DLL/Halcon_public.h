
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



//����-Ԥ�������;
typedef struct _CLASS_PREPRO_//����-Ԥ�������;
{
	//��ͼ;
	//HTuple hv_label; //
	//HTuple hv_SubFile; //
	//HTuple hv_ImageBaseFolder;//��ѡ���Ե������ļ�;
	//HTuple hv_RawImageFolder;//���·����·���������ļ�Ϊѵ���ļ�;
	//HTuple hv_ModelFileName;
	//HTuple hv_AllDataSaveDir;


	HTuple hv_LabelSource ;//������ǩ��ͬ��ʽ//* LabelSource���ڶ�ȡ���ݼ���;//'last_folder'����ļ�����Ϊ������ǩ;//'file_name'�ļ�����Ϊ������ǩ;//'file_name_remove_index'�ļ�����ȥ���������֮����Ϊ������ǩ;
	HTuple hv_Class_DLDataset ;
	HTuple  hv_TrainingValidationPercent;
	HTuple  hv_ImagePreprocessFeatures ;
// 	HTuple  hv_ImageWidth ;
// 	HTuple  hv_ImageHeight ;
// 	HTuple  hv_ImageChannels ;
// 	HTuple  hv_Domainhandling ;
// 	HTuple  hv_NormalizationType ;
	HTuple  hv_DLDatasetFileName ;//ͼ���ֵ�·��;
	HTuple  hv_DataDirectory ;//ͼ���ֵ�;
	HTuple  hv_PreprocessParamFile ;//Ԥ��������ֵ�·��;
	HTuple  hv_DLPreprocessParam ;//Ԥ��������ֵ�;
	HTuple  hv_Is_overwrite_files ;
	HTuple  hv_constant_values_mean_values_normalization ;
	HTuple  hv_constant_values_deviation_values_normalization ;
	HTuple  hv_ClassNames ;
	HTuple  hv_ClassIDs ;

}CLASS_PREPRO_S;// ����-Ԥ����;


//����-ѵ������;
typedef struct _CLASS_Train_
{
	//����-ѵ������;
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