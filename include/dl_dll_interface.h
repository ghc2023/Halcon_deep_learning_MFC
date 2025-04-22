#ifndef __DL_DLL_INTERFACE_H__
#define __DL_DLL_INTERFACE_H__


#ifndef DL_DLL_API
#define DL_DLL_API       __declspec(dllexport)
#else
#define DL_DLL_API       __declspec(dllimport) 
#endif

#include "Halconcpp.h"
using namespace HalconCpp;

#include "dl_export.h"
#include "dl_visualization.h"
#include "dev_update_off.h"



#ifdef __cplusplus
extern "C"
{
#endif
	// DL_DLL_API

	////////////////////////////////////////////

//	// Procedure declarations 
// 	extern void add_colormap_to_image_ht(HObject ho_GrayValueImage, HObject ho_Image,
// 		HObject *ho_ColoredImage, HTuple hv_HeatmapColorScheme);
// 	extern void add_colormap_to_image_ht(HObject ho_GrayValueImage, HObject ho_Image,
// 		HObject *ho_ColoredImage, HTuple hv_HeatmapColorScheme);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Compute thresholds for DL Anomaly Detection. 
// 	extern void compute_dl_anomaly_thresholds_ht(HTuple hv_DLModelHandle, HTuple hv_DLDataset,
// 		HTuple hv_GenParam, HTuple *hv_AnomalySegmentationThreshold, HTuple *hv_AnomalyClassificationThresholds);
// 	extern void create_counting_result_text_ht(HTuple hv_NumberDetectionsPerClass, HTuple hv_ClassNames,
// 		HTuple *hv_Text, HTuple *hv_TextColor, HTuple *hv_TextBoxColor);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Creates a dictionary with the preprocessing parameters based on a given DL model. 
// 	extern void create_dl_preprocess_param_from_model_ht(HTuple hv_DLModelHandle, HTuple hv_NormalizationType,
// 		HTuple hv_DomainHandling, HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground,
// 		HTuple hv_GenParam, HTuple *hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Creates a dictionary with the preprocessing parameters based on a given DL model. 
// 	extern void create_dl_preprocess_param_from_model_ht(HTuple hv_DLModelHandle, HTuple hv_NormalizationType,
// 		HTuple hv_DomainHandling, HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground,
// 		HTuple hv_GenParam, HTuple *hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Creates a dictionary with preprocessing parameters. 
// 	extern void create_dl_preprocess_param_ht(HTuple hv_DLModelType, HTuple hv_ImageWidth,
// 		HTuple hv_ImageHeight, HTuple hv_ImageNumChannels, HTuple hv_ImageRangeMin, HTuple hv_ImageRangeMax,
// 		HTuple hv_NormalizationType, HTuple hv_DomainHandling, HTuple hv_IgnoreClassIDs,
// 		HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground, HTuple hv_GenParam,
// 		HTuple *hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Creates a dictionary with preprocessing parameters. 
// 	extern void create_dl_preprocess_param_ht(HTuple hv_DLModelType, HTuple hv_ImageWidth,
// 		HTuple hv_ImageHeight, HTuple hv_ImageNumChannels, HTuple hv_ImageRangeMin, HTuple hv_ImageRangeMax,
// 		HTuple hv_NormalizationType, HTuple hv_DomainHandling, HTuple hv_IgnoreClassIDs,
// 		HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground, HTuple hv_GenParam,
// 		HTuple *hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Creates a dictionary with preprocessing parameters. 
// 	extern void create_dl_preprocess_param_ht(HTuple hv_DLModelType, HTuple hv_ImageWidth,
// 		HTuple hv_ImageHeight, HTuple hv_ImageNumChannels, HTuple hv_ImageRangeMin, HTuple hv_ImageRangeMax,
// 		HTuple hv_NormalizationType, HTuple hv_DomainHandling, HTuple hv_IgnoreClassIDs,
// 		HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground, HTuple hv_GenParam,
// 		HTuple *hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Create a training parameter dictionary which is used in train_dl_model. 
// 	extern void create_dl_train_param_ht(HTuple hv_DLModelHandle, HTuple hv_NumEpochs,
// 		HTuple hv_EvaluationIntervalEpochs, HTuple hv_EnableDisplay, HTuple hv_RandomSeed,
// 		HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple *hv_TrainParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Create a training parameter dictionary which is used in train_dl_model. 
// 	extern void create_dl_train_param_ht(HTuple hv_DLModelHandle, HTuple hv_NumEpochs,
// 		HTuple hv_EvaluationIntervalEpochs, HTuple hv_EnableDisplay, HTuple hv_RandomSeed,
// 		HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple *hv_TrainParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Create a training parameter dictionary which is used in train_dl_model. 
// 	extern void create_dl_train_param_ht(HTuple hv_DLModelHandle, HTuple hv_NumEpochs,
// 		HTuple hv_EvaluationIntervalEpochs, HTuple hv_EnableDisplay, HTuple hv_RandomSeed,
// 		HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple *hv_TrainParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Create a training parameter dictionary which is used in train_dl_model. 
// 	extern void create_dl_train_param_ht(HTuple hv_DLModelHandle, HTuple hv_NumEpochs,
// 		HTuple hv_EvaluationIntervalEpochs, HTuple hv_EnableDisplay, HTuple hv_RandomSeed,
// 		HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple *hv_TrainParam);
// 	// Chapter: Deep Learning / Object Detection
// 	// Short Description: Analyze the provided DLDataset for object detection to find model parameters relevant for anchor generation. 
// 	extern void determine_dl_model_detection_param_ht(HTuple hv_DLDataset, HTuple hv_ImageWidthTarget,
// 		HTuple hv_ImageHeightTarget, HTuple hv_GenParam, HTuple hv_WindowHandles, HTuple *hv_DLDetectionModelParam);
// 	// Chapter: Deep Learning / Object Detection
// 	// Short Description: Analyze the provided DLDataset for object detection to find model parameters relevant for anchor generation. 
// 	extern void determine_dl_model_detection_param_ht(HTuple hv_DLDataset, HTuple hv_ImageWidthTarget,
// 		HTuple hv_ImageHeightTarget, HTuple hv_GenParam, HTuple hv_WindowHandles, HTuple *hv_DLDetectionModelParam);
// 	// Chapter: Graphics / Window
// 	// Short Description: Close all window handles contained in a dictionary. 
// 	extern void dev_close_window_dict(HTuple hv_WindowHandleDict);
// 	// Chapter: Graphics / Window
// 	// Short Description: Close all window handles contained in a dictionary. 
// 	extern void dev_close_window_dict(HTuple hv_WindowHandleDict);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display an interactive button. 
// 	extern void dev_disp_button(HTuple hv_String, HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
// 		HTuple hv_Height, HTuple hv_ColorString, HTuple hv_ColorBackground, HTuple hv_ColorBackgroundActive,
// 		HTuple hv_WindowHandle, HTuple *hv_SelectedButton);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display an interactive button. 
// 	extern void dev_disp_button(HTuple hv_String, HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
// 		HTuple hv_Height, HTuple hv_ColorString, HTuple hv_ColorBackground, HTuple hv_ColorBackgroundActive,
// 		HTuple hv_WindowHandle, HTuple *hv_SelectedButton);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Display evaluation results of an evaluated DL model of type 'anomaly_detection'. 
// 	extern void dev_display_anomaly_detection_evaluation(HTuple hv_EvaluationResult,
// 		HTuple hv_EvalParam, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Display evaluation results of an evaluated DL model of type 'classification'. 
// 	extern void dev_display_classification_evaluation(HTuple hv_EvaluationResult, HTuple hv_EvalParam,
// 		HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display a map of the confidences. 
// 	extern void dev_display_confidence_regions_ht(HObject ho_ImageConfidence, HTuple hv_DrawTransparency,
// 		HTuple *hv_Colors);
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Visualize the results of a detailed evaluation for a model of type detection. 
// 	extern void dev_display_detection_detailed_evaluation(HTuple hv_EvaluationResult,
// 		HTuple hv_EvalParam, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Visualize the results of a detailed evaluation for a model of type detection. 
// 	extern void dev_display_detection_detailed_evaluation(HTuple hv_EvaluationResult,
// 		HTuple hv_EvalParam, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Visualize different images, annotations and inference results for a sample. 
// 	extern void dev_display_dl_data(HTuple hv_DLSample, HTuple hv_DLResult, HTuple hv_DLDatasetInfo,
// 		HTuple hv_KeysForDisplay, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Visualize different images, annotations and inference results for a sample. 
// 	extern void dev_display_dl_data(HTuple hv_DLSample, HTuple hv_DLResult, HTuple hv_DLDatasetInfo,
// 		HTuple hv_KeysForDisplay, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Visualize different images, annotations and inference results for a sample. 
// 	extern void dev_display_dl_data(HTuple hv_DLSample, HTuple hv_DLResult, HTuple hv_DLDatasetInfo,
// 		HTuple hv_KeysForDisplay, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Display the ground truth anomaly regions of the given DLSample. 
// 	extern void dev_display_ground_truth_anomaly_regions_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
// 		HTuple hv_CurrentWindowHandle, HTuple hv_LineWidth, HTuple hv_AnomalyRegionLabelColor,
// 		HTuple hv_AnomalyColorTransparency, HTuple *hv_AnomalyRegionExists);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Display the ground truth anomaly regions of the given DLSample. 
// 	extern void dev_display_ground_truth_anomaly_regions_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
// 		HTuple hv_CurrentWindowHandle, HTuple hv_LineWidth, HTuple hv_AnomalyRegionLabelColor,
// 		HTuple hv_AnomalyColorTransparency, HTuple *hv_AnomalyRegionExists);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display the ground truth bounding boxes of DLSample. 
// 	extern void dev_display_ground_truth_detection_ht(HTuple hv_DLSample, HTuple hv_SampleKeys,
// 		HTuple hv_LineWidthBbox, HTuple hv_ClassIDs, HTuple hv_BboxColors, HTuple hv_BboxLabelColor,
// 		HTuple hv_TextColor, HTuple hv_ShowLabels, HTuple hv_ShowDirection, HTuple hv_WindowHandle,
// 		HTuple *hv_BboxIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display the ground truth bounding boxes of DLSample. 
// 	extern void dev_display_ground_truth_detection_ht(HTuple hv_DLSample, HTuple hv_SampleKeys,
// 		HTuple hv_LineWidthBbox, HTuple hv_ClassIDs, HTuple hv_BboxColors, HTuple hv_BboxLabelColor,
// 		HTuple hv_TextColor, HTuple hv_ShowLabels, HTuple hv_ShowDirection, HTuple hv_WindowHandle,
// 		HTuple *hv_BboxIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display a color bar next to an image. 
// 	extern void dev_display_map_color_bar_ht(HTuple hv_ImageWidth, HTuple hv_ImageHeight,
// 		HTuple hv_MapColorBarWidth, HTuple hv_Colors, HTuple hv_MaxValue, HTuple hv_WindowImageRatio,
// 		HTuple hv_WindowHandle);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display a color bar next to an image. 
// 	extern void dev_display_map_color_bar_ht(HTuple hv_ImageWidth, HTuple hv_ImageHeight,
// 		HTuple hv_MapColorBarWidth, HTuple hv_Colors, HTuple hv_MaxValue, HTuple hv_WindowImageRatio,
// 		HTuple hv_WindowHandle);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Display the detected anomaly regions. 
// 	extern void dev_display_result_anomaly_regions_ht(HObject ho_AnomalyImage, HObject *ho_AnomalyRegion,
// 		HTuple hv_CurrentWindowHandle, HTuple hv_AnomalyRegionThreshold, HTuple hv_LineWidth,
// 		HTuple hv_AnomalyRegionResultColor);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Display the detected anomaly regions. 
// 	extern void dev_display_result_anomaly_regions_ht(HObject ho_AnomalyImage, HObject *ho_AnomalyRegion,
// 		HTuple hv_CurrentWindowHandle, HTuple hv_AnomalyRegionThreshold, HTuple hv_LineWidth,
// 		HTuple hv_AnomalyRegionResultColor);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display result bounding boxes. 
// 	extern void dev_display_result_detection_ht(HTuple hv_DLResult, HTuple hv_ResultKeys,
// 		HTuple hv_LineWidthBbox, HTuple hv_ClassIDs, HTuple hv_TextConf, HTuple hv_Colors,
// 		HTuple hv_BoxLabelColor, HTuple hv_WindowImageRatio, HTuple hv_TextPositionRow,
// 		HTuple hv_TextColor, HTuple hv_ShowLabels, HTuple hv_ShowDirection, HTuple hv_WindowHandle,
// 		HTuple *hv_BboxIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display result bounding boxes. 
// 	extern void dev_display_result_detection_ht(HTuple hv_DLResult, HTuple hv_ResultKeys,
// 		HTuple hv_LineWidthBbox, HTuple hv_ClassIDs, HTuple hv_TextConf, HTuple hv_Colors,
// 		HTuple hv_BoxLabelColor, HTuple hv_WindowImageRatio, HTuple hv_TextPositionRow,
// 		HTuple hv_TextColor, HTuple hv_ShowLabels, HTuple hv_ShowDirection, HTuple hv_WindowHandle,
// 		HTuple *hv_BboxIDs);
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Visualize the results of an evaluation for a model of type segmentation. 
// 	extern void dev_display_segmentation_evaluation(HTuple hv_EvaluationResult, HTuple hv_EvalParam,
// 		HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display the ground truth/result segmentation as regions. 
// 	extern void dev_display_segmentation_regions_ht(HObject ho_SegmentationImage, HTuple hv_ClassIDs,
// 		HTuple hv_ColorsSegmentation, HTuple hv_ExcludeClassIDs, HTuple *hv_ImageClassIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display the ground truth/result segmentation as regions. 
// 	extern void dev_display_segmentation_regions_ht(HObject ho_SegmentationImage, HTuple hv_ClassIDs,
// 		HTuple hv_ColorsSegmentation, HTuple hv_ExcludeClassIDs, HTuple *hv_ImageClassIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display the ground truth/result segmentation as regions. 
// 	extern void dev_display_segmentation_regions_ht(HObject ho_SegmentationImage, HTuple hv_ClassIDs,
// 		HTuple hv_ColorsSegmentation, HTuple hv_ExcludeClassIDs, HTuple *hv_ImageClassIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display the ground truth/result segmentation as regions. 
// 	extern void dev_display_segmentation_regions_ht(HObject ho_SegmentationImage, HTuple hv_ClassIDs,
// 		HTuple hv_ColorsSegmentation, HTuple hv_ExcludeClassIDs, HTuple *hv_ImageClassIDs);
// 	// Chapter: Graphics / Output
// 	// Short Description: Display a map of weights. 
// 	extern void dev_display_weight_regions_ht(HObject ho_ImageWeight, HTuple hv_DrawTransparency,
// 		HTuple hv_SegMaxWeight, HTuple *hv_Colors);
// 	// Chapter: Develop
// 	// Short Description: Resizes a graphics window with a given maximum extent such that it preserves the aspect ratio of a given width and height 
// 	extern void dev_resize_window_fit_size(HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
// 		HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit);
// 	// Chapter: Develop
// 	// Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'. 
// 	extern void dev_update_off();
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
// 	extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
// 		HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
// 		HTuple *hv_EvalParams);
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
// 	extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
// 		HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
// 		HTuple *hv_EvalParams);
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
// 	extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
// 		HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
// 		HTuple *hv_EvalParams);
// 	// Chapter: Deep Learning / Evaluation
// 	// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
// 	extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
// 		HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
// 		HTuple *hv_EvalParams);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Retrieve the indices of Samples that contain KeyName matching KeyValue according to the Mode set. 
// 	extern void find_dl_samples_ht(HTuple hv_Samples, HTuple hv_KeyName, HTuple hv_KeyValue,
// 		HTuple hv_Mode, HTuple *hv_SampleIndices);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Retrieve the indices of Samples that contain KeyName matching KeyValue according to the Mode set. 
// 	extern void find_dl_samples_ht(HTuple hv_Samples, HTuple hv_KeyName, HTuple hv_KeyValue,
// 		HTuple hv_Mode, HTuple *hv_SampleIndices);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Retrieve the indices of Samples that contain KeyName matching KeyValue according to the Mode set. 
// 	extern void find_dl_samples_ht(HTuple hv_Samples, HTuple hv_KeyName, HTuple hv_KeyValue,
// 		HTuple hv_Mode, HTuple *hv_SampleIndices);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Compute a confusion matrix, which an be visualized and/or returned. 
// 	extern void gen_confusion_matrix(HTuple hv_GroundTruthLabels, HTuple hv_PredictedClasses,
// 		HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple hv_WindowHandle, HTuple *hv_ConfusionMatrix);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Return the confidence based heatmap of a deep learning classification in DLResult. 
// 	extern void gen_dl_model_classification_heatmap(HTuple hv_DLModelHandle, HTuple hv_DLSample,
// 		HTuple hv_DLResult, HTuple hv_GenParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Store the given images in a tuple of dictionaries DLSamples. 
// 	extern void gen_dl_samples_from_images_ht(HObject ho_Images, HTuple *hv_DLSampleBatch);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Store the given images in a tuple of dictionaries DLSamples. 
// 	extern void gen_dl_samples_from_images_ht(HObject ho_Images, HTuple *hv_DLSampleBatch);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Store the given images in a tuple of dictionaries DLSamples. 
// 	extern void gen_dl_samples_from_images_ht(HObject ho_Images, HTuple *hv_DLSampleBatch);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Get the ground truth anomaly label and label ID. 
// 	extern void get_anomaly_ground_truth_label_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
// 		HTuple *hv_AnomalyLabelGroundTruth, HTuple *hv_AnomalyLabelIDGroundTruth);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Get the ground truth anomaly label and label ID. 
// 	extern void get_anomaly_ground_truth_label_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
// 		HTuple *hv_AnomalyLabelGroundTruth, HTuple *hv_AnomalyLabelIDGroundTruth);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Get the anomaly image out of DLResult. 
// 	extern void get_anomaly_result_ht(HObject *ho_AnomalyImage, HTuple hv_ResultKeys,
// 		HTuple hv_DLResult, HTuple *hv_AnomalyScore, HTuple *hv_AnomalyClassID);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Get the anomaly image out of DLResult. 
// 	extern void get_anomaly_result_ht(HObject *ho_AnomalyImage, HTuple hv_ResultKeys,
// 		HTuple hv_DLResult, HTuple *hv_AnomalyScore, HTuple *hv_AnomalyClassID);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Get the anomaly image out of DLResult. 
// 	extern void get_anomaly_result_ht(HObject *ho_AnomalyImage, HTuple hv_ResultKeys,
// 		HTuple hv_DLResult, HTuple *hv_AnomalyScore, HTuple *hv_AnomalyClassID);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next child window that can be used for visualization. 
// 	extern void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
// 		HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Get the ground truth classification label id. 
// 	extern void get_classification_ground_truth_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
// 		HTuple *hv_ClassificationLabelIDGroundTruth);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Get the ground truth classification label id. 
// 	extern void get_classification_ground_truth_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
// 		HTuple *hv_ClassificationLabelIDGroundTruth);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Get the predicted classification class ID. 
// 	extern void get_classification_result_ht(HTuple hv_ResultKeys, HTuple hv_DLResult,
// 		HTuple *hv_ClassificationClassID);
// 	// Chapter: Deep Learning / Classification
// 	// Short Description: Get the predicted classification class ID. 
// 	extern void get_classification_result_ht(HTuple hv_ResultKeys, HTuple hv_DLResult,
// 		HTuple *hv_ClassificationClassID);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the confidences of the segmentation result. 
// 	extern void get_confidence_image_ht(HObject *ho_ImageConfidence, HTuple hv_ResultKeys,
// 		HTuple hv_DLResult);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the confidences of the segmentation result. 
// 	extern void get_confidence_image_ht(HObject *ho_ImageConfidence, HTuple hv_ResultKeys,
// 		HTuple hv_DLResult);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Generates certain colors for different ClassNames 
// 	extern void get_dl_class_colors_ht(HTuple hv_ClassNames, HTuple *hv_Colors);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Get the image of a sample. 
// 	extern void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Graphics / Window
// 	// Short Description: Get the next window that can be used for visualization. 
// 	extern void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
// 		HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
// 		HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
// 		HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
// 		HTuple *hv_PrevWindowCoordinatesOut);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the ground truth segmentation image. 
// 	extern void get_segmentation_image_ground_truth_ht(HObject *ho_SegmentationImagGroundTruth,
// 		HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the ground truth segmentation image. 
// 	extern void get_segmentation_image_ground_truth_ht(HObject *ho_SegmentationImagGroundTruth,
// 		HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the ground truth segmentation image. 
// 	extern void get_segmentation_image_ground_truth_ht(HObject *ho_SegmentationImagGroundTruth,
// 		HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the predicted segmentation result image. 
// 	extern void get_segmentation_image_result_ht(HObject *ho_SegmentationImageResult,
// 		HTuple hv_ResultKeys, HTuple hv_DLResult);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the predicted segmentation result image. 
// 	extern void get_segmentation_image_result_ht(HObject *ho_SegmentationImageResult,
// 		HTuple hv_ResultKeys, HTuple hv_DLResult);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the predicted segmentation result image. 
// 	extern void get_segmentation_image_result_ht(HObject *ho_SegmentationImageResult,
// 		HTuple hv_ResultKeys, HTuple hv_DLResult);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the weight image of a sample. 
// 	extern void get_weight_image(HObject *ho_ImageWeight, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Get the weight image of a sample. 
// 	extern void get_weight_image_ht(HObject *ho_ImageWeight, HTuple hv_SampleKeys, HTuple hv_DLSample);
// 	// Chapter: File / Misc
// 	extern void images_exist_ht(HTuple hv_ImageList);
// 	// Chapter: File / Misc
// 	extern void images_exist_ht(HTuple hv_ImageList);
// 	// Chapter: File / Misc
// 	extern void images_exist_ht(HTuple hv_ImageList);
// 	// Chapter: File / Misc
// 	extern void images_exist_ht(HTuple hv_ImageList);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Generate image list and corresponding annotation file list. 
// 	extern void list_image_and_annotation_files_ht(HTuple hv_Type, HTuple hv_ImageDir,
// 		HTuple hv_AnnotationDir, HTuple hv_ImageListIn, HTuple hv_GenParam, HTuple *hv_ImageListOut,
// 		HTuple *hv_LabelListOut, HTuple *hv_AnnotationListOut);
// 	// Chapter: Deep Learning / Semantic Segmentation
// 	// Short Description: Generate image list and corresponding annotation file list. 
// 	extern void list_image_and_annotation_files_ht(HTuple hv_Type, HTuple hv_ImageDir,
// 		HTuple hv_AnnotationDir, HTuple hv_ImageListIn, HTuple hv_GenParam, HTuple *hv_ImageListOut,
// 		HTuple *hv_LabelListOut, HTuple *hv_AnnotationListOut);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Standard preprocessing on the entire dataset declared in DLDataset. 
// 	extern void preprocess_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_DataDirectory,
// 		HTuple hv_DLPreprocessParam, HTuple hv_GenParam, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Standard preprocessing on the entire dataset declared in DLDataset. 
// 	extern void preprocess_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_DataDirectory,
// 		HTuple hv_DLPreprocessParam, HTuple hv_GenParam, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Standard preprocessing on the entire dataset declared in DLDataset. 
// 	extern void preprocess_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_DataDirectory,
// 		HTuple hv_DLPreprocessParam, HTuple hv_GenParam, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Standard preprocessing on the entire dataset declared in DLDataset. 
// 	extern void preprocess_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_DataDirectory,
// 		HTuple hv_DLPreprocessParam, HTuple hv_GenParam, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Standard preprocessing on the entire dataset declared in DLDataset. 
// 	extern void preprocess_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_DataDirectory,
// 		HTuple hv_DLPreprocessParam, HTuple hv_GenParam, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Preprocess given DLSamples according to the preprocessing parameters given in DLPreprocessParam. 
// 	extern void preprocess_dl_samples_ht(HTuple hv_DLSampleBatch, HTuple hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Preprocess given DLSamples according to the preprocessing parameters given in DLPreprocessParam. 
// 	extern void preprocess_dl_samples_ht(HTuple hv_DLSampleBatch, HTuple hv_DLPreprocessParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Preprocess given DLSamples according to the preprocessing parameters given in DLPreprocessParam. 
// 	extern void preprocess_dl_samples_ht(HTuple hv_DLSampleBatch, HTuple hv_DLPreprocessParam);
// 	// Chapter: Graphics / Text
// 	// Short Description: Set font independent of OS 
// 	extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
// 		HTuple hv_Bold, HTuple hv_Slant);
// 	// Chapter: Graphics / Text
// 	// Short Description: Set font independent of OS 
// 	extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
// 		HTuple hv_Bold, HTuple hv_Slant);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Set the model parameters based on preprocessing parameters. 
// 	extern void set_dl_model_param_based_on_preprocessing_ht(HTuple hv_DLModelHandle,
// 		HTuple hv_DLPreprocessParam, HTuple hv_ClassIDs);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Set the maximum batch size for a given DLModelHandle and GPU. 
// 	extern void set_dl_model_param_max_gpu_batch_size_ht(HTuple hv_DLModelHandle, HTuple hv_BatchSizeUpperBound);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Set the maximum batch size for a given DLModelHandle and GPU. 
// 	extern void set_dl_model_param_max_gpu_batch_size_ht(HTuple hv_DLModelHandle, HTuple hv_BatchSizeUpperBound);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Set the maximum batch size for a given DLModelHandle and GPU. 
// 	extern void set_dl_model_param_max_gpu_batch_size_ht(HTuple hv_DLModelHandle, HTuple hv_BatchSizeUpperBound);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Split the samples into training, validation, and test subsets. 
// 	extern void split_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_TrainingPercent,
// 		HTuple hv_ValidationPercent, HTuple hv_GenParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Split the samples into training, validation, and test subsets. 
// 	extern void split_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_TrainingPercent,
// 		HTuple hv_ValidationPercent, HTuple hv_GenParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Split the samples into training, validation, and test subsets. 
// 	extern void split_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_TrainingPercent,
// 		HTuple hv_ValidationPercent, HTuple hv_GenParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Split the samples into training, validation, and test subsets. 
// 	extern void split_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_TrainingPercent,
// 		HTuple hv_ValidationPercent, HTuple hv_GenParam);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Split the samples into training, validation, and test subsets. 
// 	extern void split_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_TrainingPercent,
// 		HTuple hv_ValidationPercent, HTuple hv_GenParam);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Apply the given thresholds on anomaly detection results for image classification and region segmentation. 
// 	extern void threshold_dl_anomaly_results_ht(HTuple hv_AnomalySegmentationThreshold,
// 		HTuple hv_AnomalyClassificationThreshold, HTuple hv_DLResults);
// 	// Chapter: Deep Learning / Anomaly Detection
// 	// Short Description: Apply the given thresholds on anomaly detection results for image classification and region segmentation. 
// 	extern void threshold_dl_anomaly_results_ht(HTuple hv_AnomalySegmentationThreshold,
// 		HTuple hv_AnomalyClassificationThreshold, HTuple hv_DLResults);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Train a deep-learning-based model on a dataset. 
// 	extern void train_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainParam,
// 		HTuple hv_StartEpoch, HTuple hv_WindowHandles, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
// 		HTuple *hv_EvaluationInfos);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Train a deep-learning-based model on a dataset. 
// 	extern void train_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainParam,
// 		HTuple hv_StartEpoch, HTuple hv_WindowHandles, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
// 		HTuple *hv_EvaluationInfos);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Train a deep-learning-based model on a dataset. 
// 	extern void train_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainParam,
// 		HTuple hv_StartEpoch, HTuple hv_WindowHandles, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
// 		HTuple *hv_EvaluationInfos);
// 	// Chapter: Deep Learning / Model
// 	// Short Description: Train a deep-learning-based model on a dataset. 
// 	extern void train_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainParam,
// 		HTuple hv_StartEpoch, HTuple hv_WindowHandles, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
// 		HTuple *hv_EvaluationInfos);
DL_DLL_API	void Anomaly_Display_preprocess(HTuple hv_DLDataset, HTuple hv_TrainingValidationPercent,
		HTuple hv_ImagePreprocessFeatures, HTuple hv_is_overwrite_files, HTuple hv_AllDataSaveDir,
		HTuple hv_isdisplay, HTuple hv_WindowHandles, HTuple hv_stoptime, HTuple *hv_PreprocessParamFile,
		HTuple *hv_DataDirectory, HTuple *hv_DLPreprocessParam, HTuple *hv_DLDatasetFileName);
DL_DLL_API	void Anomaly_Evaluation_Display(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_AnomalyClassificationThresholds,
		HTuple hv_AnomalySegmentationThreshold, HTuple hv_isDisplay, HTuple hv_WindowHandles,
		HTuple *hv_EvaluationResult, HTuple *hv_EvalParams);
DL_DLL_API	void Anomaly_Infer_Apply_Dl_Model(HObject ho_Image, HTuple hv_DLModelHandle, HTuple hv_DLPreprocessParam,
		HTuple hv_IsDispaly, HTuple hv_WindowHandles, HTuple hv_GenParam, HTuple hv_WindowDict,
		HTuple hv_DLDataInfo);
DL_DLL_API	void Anomaly_Infer_Set_Param(HTuple hv_DLModelHandle, HTuple hv_UseGPU, HTuple hv_BatchSize,
		HTuple hv_AnomalyClassificationThresholds, HTuple hv_AnomalySegmentationThreshold,
		HTuple *hv_GenParam, HTuple *hv_DLDatasetInfo);
DL_DLL_API	void Anomaly_Train_DL_Model(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_DLModelTrainParam,
		HTuple hv_TrainParamAnomaly, HTuple hv_AllDataSaveDir, HTuple hv_WindowHandles,
		HTuple hv_IsDisply, HTuple *hv_TrainResults, HTuple *hv_DLModelFileName, HTuple *hv_AnomalySegmentationThreshold,
		HTuple *hv_AnomalyClassificationThresholds, HTuple *hv_TrainInfos, HTuple *hv_EvaluationInfos);
DL_DLL_API	void Class_Display_heatmap(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_HeatmapGTInfClassName,
		HTuple hv_EvaluationResult, HTuple hv_HeatmapMethod, HTuple hv_WindowHandles,
		HTuple hv_UseGPU, HTuple hv_waitsecond);
DL_DLL_API	void Class_Evaluation_Display(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_UseGPU,
		HTuple hv_BatchSize, HTuple hv_ClassificationMeasures, HTuple hv_windowHandles,
		HTuple *hv_EvaluationResult, HTuple *hv_EvalParams);
DL_DLL_API	void Class_Infer_Apply_Dl_Model(HObject ho_ImageBatch, HTuple hv_DLModelHandle,
		HTuple hv_DLPreprocessParam, HTuple hv_BatchSizeInference, HTuple hv_Isdisplay,
		HTuple hv_DLDataInfo, HTuple hv_GenParam, HTuple hv_WindowHandleDict, HTuple hv_KeysForDisplay,
		HTuple *hv_DLResultBatch);
DL_DLL_API	void Class_Infer_Set_Display_Param(HTuple hv_ClassNames, HTuple hv_ClassIDs, HTuple hv_WindowHandles,
		HTuple hv_KeysForDisplay, HTuple hv_scalewindows, HTuple *hv_WindowHandleDict,
		HTuple *hv_DLDataInfo, HTuple *hv_GenParam);
DL_DLL_API	void Class_Infer_Set_DL_Model_Param(HTuple hv_DLModelHandle, HTuple hv_UseGPU, HTuple hv_BatchSizeInference,
		HTuple *hv_ClassNames, HTuple *hv_ClassIDs);
DL_DLL_API	void Class_Train_DL_Model(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainSetParam,
		HTuple hv_DispaySetParam, HTuple hv_DLPreprocessParam, HTuple hv_WindowHandles,
		HTuple hv_ClassBestFinaModelBaseNameSavePath, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
		HTuple *hv_EvaluationInfos);
DL_DLL_API	void Classify_Preprocess(HTuple hv_DLDataset, HTuple hv_TrainingValidationPercent,
		HTuple hv_ImagePreprocessFeatures, HTuple hv_is_overwrite_files, HTuple hv_AllDataSaveDir,
		HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName, HTuple *hv_DataDirectory,
		HTuple *hv_PreprocessParamFile, HTuple *hv_DLPreprocessParam);
DL_DLL_API	void Detect_Evaluation_Display(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_UseGPU,
		HTuple hv_BatchSize, HTuple hv_DetectMeasuresParamDict, HTuple hv_ModelParamDict,
		HTuple hv_windowHandles, HTuple *hv_EvaluationResultDetection, HTuple *hv_EvalParams);
DL_DLL_API	void Detect_Infer_Apply_Dl_Model(HObject ho_ImageBatch, HTuple hv_DLModelHandle,
		HTuple hv_DLPreprocessParam, HTuple hv_BatchSizeInference, HTuple hv_isdisplay,
		HTuple hv_DLDataInfo, HTuple hv_GenParam, HTuple hv_WindowHandleDict, HTuple hv_KeysForDisplay,
		HTuple *hv_DLResultBatch);
DL_DLL_API	void Detect_Infer_Set_Display_Param(HTuple hv_ClassNames, HTuple hv_ClassIDs, HTuple hv_WindowHandles,
		HTuple hv_KeysForDisplay, HTuple hv_scalewindows, HTuple *hv_WindowHandleDict,
		HTuple *hv_DLDataInfo, HTuple *hv_GenParam);
DL_DLL_API	void Detect_Infer_Set_DL_Model_Param(HTuple hv_DLModelHandle, HTuple hv_UseGPU,
		HTuple hv_BatchSizeInference, HTuple hv_MinConfidence, HTuple hv_MaxOverlap,
		HTuple hv_MaxOverlapClassAgnostic);
DL_DLL_API	void Detect_preprocess_CreateDLDetectModel(HTuple hv_DLDataset, HTuple hv_TrainingValidationPercent,
		HTuple hv_ImagePreprocessFeatures, HTuple hv_Backbone, HTuple hv_Capacity, HTuple hv_is_overwrite_files,
		HTuple hv_AllSaveDataDir, HTuple hv_WindowHandles, HTuple *hv_DLModelHandle,
		HTuple *hv_DLPreprocessParam, HTuple *hv_DLModelFileName, HTuple *hv_DataDirectory,
		HTuple *hv_PreprocessParamFileName, HTuple *hv_DLDatasetFilename);
DL_DLL_API	void Detect_Rectangle2_preprocess_CreateDLDetectModel(HTuple hv_DLDataset, HTuple hv_TrainingValidationPercent,
		HTuple hv_ImagePreprocessFeatures, HTuple hv_Backbone, HTuple hv_Capacity, HTuple hv_is_overwrite_files,
		HTuple hv_AllSaveDataDir, HTuple hv_WindowHandles, HTuple hv_DLModelDetectionRectangle2Param,
		HTuple *hv_DLModelHandle, HTuple *hv_DLPreprocessParam, HTuple *hv_DLModelFileName,
		HTuple *hv_DataDirectory, HTuple *hv_PreprocessParamFileName, HTuple *hv_DLDatasetFileName);
DL_DLL_API	void Detect_Train_DL_Model(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainSetParam,
		HTuple hv_DispaySetParam, HTuple hv_WindowHandles, HTuple hv_DetectBestFinaModelBaseNameSavePath,
		HTuple *hv_TrainResults, HTuple *hv_TrainInfos, HTuple *hv_EvaluationInfos);
DL_DLL_API	void Dev_Display_Class_PreprocesSamples(HTuple hv_DLDataset, HTuple hv_WindowHandles,
		HTuple hv_SplitSamplesName, HTuple hv_SamplesNums, HTuple hv_KeysForDisplay,
		HTuple hv_WaitTime);
DL_DLL_API	void Dev_Display_Detect_PreprocesSamples(HTuple hv_DLDataset, HTuple hv_WindowHandles,
		HTuple hv_SplitSamplesName, HTuple hv_SamplesNums, HTuple hv_WaitTime);
	// Chapter: Deep Learning / Model
	// Short Description: Visualize different images, annotations and inference results for a sample. 
DL_DLL_API	void dev_display_dl_data_ht(HTuple hv_DLSample, HTuple hv_DLResult, HTuple hv_DLDatasetInfo,
		HTuple hv_KeysForDisplay, HTuple hv_GenParam, HTuple hv_WindowHandleDict, HTuple hv_WindowHandle);
DL_DLL_API	void dev_display_dl_interactive_confusion_matrix(HTuple hv_DLDataset, HTuple hv_EvaluationResult,
		HTuple hv_GenParam);
	// Chapter: File / Misc
	// Short Description: Get all image files under the given path 
DL_DLL_API	void list_image_files_ht(HTuple hv_ImageDirectory, HTuple hv_Extensions, HTuple hv_Options,
		HTuple *hv_ImageFiles);
	// Chapter: Deep Learning / Anomaly Detection
	// Short Description: Generate a DLDataset dictionary for anomaly detection. 
DL_DLL_API	void read_dl_dataset_anomaly_ht(HTuple hv_ImageDir, HTuple hv_AnomalyDir, HTuple hv_ImageList,
		HTuple hv_AnomalyList, HTuple hv_GenParam, HTuple *hv_DLDataset);
	// Chapter: Deep Learning / Classification
	// Short Description: Generate a DLDataset dictionary for classification. 
DL_DLL_API	void read_dl_dataset_classification_ht(HTuple hv_RawImageFolder, HTuple hv_LabelSource,
	HTuple *hv_DLDataset, HTuple  *hv_ClassNames, HTuple *hv_ClassIDs);
	// Chapter: Deep Learning / Object Detection
	// Short Description: Read the COCO file and convert it to the dictionary DLDataset. 
DL_DLL_API	void read_dl_dataset_from_coco_ht(HTuple hv_CocoFileName, HTuple hv_ImageDir, HTuple hv_GenParam,
		HTuple *hv_DLDataset);
	// Chapter: Deep Learning / Semantic Segmentation
	// Short Description: Generate a DLDataset dictionary for semantic segmentation. 
DL_DLL_API	void read_dl_dataset_segmentation_ht(HTuple hv_ImageDir, HTuple hv_SegmentationDir,
		HTuple hv_ClassNames, HTuple hv_ClassIDs, HTuple hv_ImageList, HTuple hv_SegmentationList,
		HTuple hv_GenParam, HTuple *hv_DLDataset);
	// Chapter: Deep Learning / Model
	// Short Description: Read the dictionaries DLSamples from files. 
DL_DLL_API	void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);

DL_DLL_API	void Segment_Evaluation_Display(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_UseGPU,
		HTuple hv_BatchSize, HTuple hv_DetectMeasuresParamDict, HTuple hv_WindowHandles,
		HTuple *hv_EvaluationResult, HTuple *hv_EvalParams);
DL_DLL_API	void Segment_Preprocess(HTuple hv_DLDataset, HTuple hv_TrainingValidationPercent,
		HTuple hv_ImagePreprocessFeatures, HTuple hv_SetClassIDImageParam, HTuple hv_is_overwrite_files,
		HTuple hv_AllSaveDataDir, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFilename,
		HTuple *hv_DataDirectory, HTuple *hv_PreprocessParamFile, HTuple *hv_DLPreprocessParam);
DL_DLL_API	void Segment_Train_DL_Model(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainSetParam,
		HTuple hv_DispaySetParam, HTuple hv_WindowHandles, HTuple hv_DetectBestFinaModelBaseNameSavePath,
		HTuple *hv_TrainResults, HTuple *hv_TrainInfos, HTuple *hv_EvaluationInfos);
	// Chapter: Tuple / Element Order
	// Short Description: Sort the elements of a tuple randomly. 
DL_DLL_API	void tuple_shuffle_ht(HTuple hv_Tuple, HTuple *hv_Shuffled);








#ifdef __cplusplus
}
#endif

#endif //__DL_DLL_INTERFACE_H__