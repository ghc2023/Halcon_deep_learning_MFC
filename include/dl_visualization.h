#ifndef __DL_VISUALIZATION_H__
#define __DL_VISUALIZATION_H__

#include "Halconcpp.h"
using namespace HalconCpp;

// Procedure declarations 
// Chapter: Graphics / Parameters
extern void color_string_to_rgb(HTuple hv_Color, HTuple *hv_RGB);
// Chapter: Graphics / Parameters
extern void color_string_to_rgb(HTuple hv_Color, HTuple *hv_RGB);
// Chapter: Graphics / Parameters
extern void color_string_to_rgb(HTuple hv_Color, HTuple *hv_RGB);
// Chapter: Graphics / Parameters
extern void color_string_to_rgb(HTuple hv_Color, HTuple *hv_RGB);

// Chapter: Graphics / Output
// Short Description: This procedure draws a pie chart into the active window handle. 
extern void dev_display_pie_chart(HTuple hv_WindowHandle, HTuple hv_Ratios, HTuple hv_Row,
	HTuple hv_Column, HTuple hv_Radius, HTuple hv_Colors, HTuple hv_GenParam);
// Chapter: Graphics / Output
// Short Description: This procedure draws a pie chart into the active window handle. 
extern void dev_display_pie_chart(HTuple hv_WindowHandle, HTuple hv_Ratios, HTuple hv_Row,
	HTuple hv_Column, HTuple hv_Radius, HTuple hv_Colors, HTuple hv_GenParam);
// Chapter: Graphics / Output
// Short Description: This procedure draws a pie chart into the active window handle. 
extern void dev_display_pie_chart(HTuple hv_WindowHandle, HTuple hv_Ratios, HTuple hv_Row,
	HTuple hv_Column, HTuple hv_Radius, HTuple hv_Colors, HTuple hv_GenParam);
// Chapter: Develop
// Short Description: Open a new graphics window that preserves the aspect ratio of the given image size. 
extern void dev_open_window_fit_size(HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
	HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle);
// Chapter: Develop
// Short Description: Resizes a graphics window with a given maximum extent such that it preserves the aspect ratio of a given width and height 
extern void dev_resize_window_fit_size(HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
	HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit);
// Chapter: Deep Learning / Evaluation
// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
	HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
	HTuple *hv_EvalParams);
// Chapter: Deep Learning / Evaluation
// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
	HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
	HTuple *hv_EvalParams);
// Chapter: Deep Learning / Evaluation
// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
	HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
	HTuple *hv_EvalParams);
// Chapter: Deep Learning / Evaluation
// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
extern void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
	HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
	HTuple *hv_EvalParams);
// Chapter: Deep Learning / Model
// Short Description: Retrieve the indices of Samples that contain KeyName matching KeyValue according to the Mode set. 
extern void find_dl_samples_ht(HTuple hv_Samples, HTuple hv_KeyName, HTuple hv_KeyValue,
	HTuple hv_Mode, HTuple *hv_SampleIndices);
// Chapter: XLD / Creation
// Short Description: Creates an arrow shaped XLD contour. 
extern void gen_arrow_contour_xld(HObject *ho_Arrow, HTuple hv_Row1, HTuple hv_Column1,
	HTuple hv_Row2, HTuple hv_Column2, HTuple hv_HeadLength, HTuple hv_HeadWidth);
// Chapter: XLD / Creation
// Short Description: Creates an arrow shaped XLD contour. 
extern void gen_arrow_contour_xld(HObject *ho_Arrow, HTuple hv_Row1, HTuple hv_Column1,
	HTuple hv_Row2, HTuple hv_Column2, HTuple hv_HeadLength, HTuple hv_HeadWidth);
// Chapter: Graphics / Output
// Short Description:  This procedure plots tuples representing functions or curves in a coordinate system. 
extern void plot_tuple_ht(HTuple hv_WindowHandle, HTuple hv_XValues, HTuple hv_YValues,
	HTuple hv_XLabel, HTuple hv_YLabel, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue);
// Chapter: Graphics / Output
// Short Description:  This procedure plots tuples representing functions or curves in a coordinate system. 
extern void plot_tuple_ht(HTuple hv_WindowHandle, HTuple hv_XValues, HTuple hv_YValues,
	HTuple hv_XLabel, HTuple hv_YLabel, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue);
// Chapter: Graphics / Output
// Short Description:  This procedure plots tuples representing functions or curves in a coordinate system. 
extern void plot_tuple_ht(HTuple hv_WindowHandle, HTuple hv_XValues, HTuple hv_YValues,
	HTuple hv_XLabel, HTuple hv_YLabel, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue);
// Chapter: Graphics / Output
// Short Description:  This procedure plots tuples representing functions or curves in a coordinate system. 
extern void plot_tuple_ht(HTuple hv_WindowHandle, HTuple hv_XValues, HTuple hv_YValues,
	HTuple hv_XLabel, HTuple hv_YLabel, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue);

// Chapter: Filters / Arithmetic
// Short Description: Scale the gray values of an image from the interval [Min,Max] to [0,255] 
extern void scale_image_range(HObject ho_Image, HObject *ho_ImageScaled, HTuple hv_Min,
	HTuple hv_Max);
// Chapter: Filters / Arithmetic
// Short Description: Scale the gray values of an image from the interval [Min,Max] to [0,255] 
extern void scale_image_range(HObject ho_Image, HObject *ho_ImageScaled, HTuple hv_Min,
	HTuple hv_Max);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
extern void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font,
	HTuple hv_Bold, HTuple hv_Slant);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Apply the given thresholds on anomaly detection results for image classification and region segmentation. 
extern void threshold_dl_anomaly_results_ht(HTuple hv_AnomalySegmentationThreshold,
	HTuple hv_AnomalyClassificationThreshold, HTuple hv_DLResults);

void add_colormap_to_image(HObject ho_GrayValueImage, HObject ho_Image, HObject *ho_ColoredImage,
	HTuple hv_HeatmapColorScheme);

// Short Description: Create a lookup table and convert a grey scale image. 
void apply_colorscheme_on_gray_value_image(HObject ho_InputImage, HObject *ho_ResultImage,
	HTuple hv_Schema);

// Chapter: Deep Learning / Anomaly Detection
// Short Description: Display evaluation results of an evaluated DL model of type 'anomaly_detection'. 
void dev_display_anomaly_detection_evaluation(HTuple hv_EvaluationResult, HTuple hv_EvalParam,
	HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// Chapter: Deep Learning / Classification
// Short Description: Display evaluation results of an evaluated DL model of type 'classification'. 
void dev_display_classification_evaluation(HTuple hv_EvaluationResult, HTuple hv_EvalParam,
	HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// Chapter: Deep Learning / Classification
// Short Description: Display pie charts for prediction or recall of an classification evaluation. 
void dev_display_classification_evaluation_class_pie_chart(HTuple hv_WindowHandle,
	HTuple hv_EvaluationResult, HTuple hv_ClassIDs, HTuple hv_Mode);
// Chapter: Graphics / Output
// Short Description: Display a map of the confidences. 
void dev_display_confidence_regions(HObject ho_ImageConfidence, HTuple hv_DrawTransparency,
	HTuple *hv_Colors);
// Chapter: Deep Learning / Evaluation
// Short Description: Display the confusion matrix for the evaluation results of a model with type detection. 
void dev_display_detection_confusion_matrix(HTuple hv_WindowHandles, HTuple hv_IoUEvaluationResult,
	HTuple hv_ClassIDs, HTuple hv_GenParam);
// Chapter: Deep Learning / Evaluation
// Short Description: Visualize the results of a detailed evaluation for a model of type detection. 
void dev_display_detection_detailed_evaluation(HTuple hv_EvaluationResult, HTuple hv_EvalParam,
	HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// Chapter: Deep Learning / Evaluation
// Short Description: Display a pie-chart for the evaluation results of one class or all classes together. 
void dev_display_detection_eval_class_pie_chart(HTuple hv_WindowHandle, HTuple hv_ClassEvaluationResult,
	HTuple hv_CenterRow, HTuple hv_Mode, HTuple hv_CenterColumn, HTuple hv_Radius,
	HTuple hv_Colors, HTuple hv_Title, HTuple *hv_Ratios);
// Chapter: Deep Learning / Evaluation
// Short Description: Display the evaluation results as pie-charts. 
void dev_display_detection_evaluation_pie_charts(HTuple hv_WindowHandle, HTuple hv_IoUEvaluationResult,
	HTuple hv_ClassIDs, HTuple hv_Mode, HTuple hv_BaseWindowRow, HTuple hv_BaseWindowColumn);
// Chapter: Deep Learning / Model
// Short Description: Visualize different images, annotations and inference results for a sample. 
void dev_display_dl_data(HTuple hv_DLSample, HTuple hv_DLResult, HTuple hv_DLDatasetInfo,
	HTuple hv_KeysForDisplay, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Display the ground truth anomaly regions of the given DLSample. 
void dev_display_ground_truth_anomaly_regions(HTuple hv_SampleKeys, HTuple hv_DLSample,
	HTuple hv_CurrentWindowHandle, HTuple hv_LineWidth, HTuple hv_AnomalyRegionLabelColor,
	HTuple hv_AnomalyColorTransparency, HTuple *hv_AnomalyRegionExists);
// Chapter: Graphics / Output
// Short Description: Display the ground truth bounding boxes of DLSample. 
void dev_display_ground_truth_detection(HTuple hv_DLSample, HTuple hv_SampleKeys,
	HTuple hv_LineWidthBbox, HTuple hv_ClassIDs, HTuple hv_BboxColors, HTuple hv_BboxLabelColor,
	HTuple hv_TextColor, HTuple hv_ShowLabels, HTuple hv_ShowDirection, HTuple hv_WindowHandle,
	HTuple *hv_BboxIDs);
// Chapter: Graphics / Output
// Short Description: Display a color bar next to an image. 
void dev_display_map_color_bar(HTuple hv_ImageWidth, HTuple hv_ImageHeight, HTuple hv_MapColorBarWidth,
	HTuple hv_Colors, HTuple hv_MaxValue, HTuple hv_WindowImageRatio, HTuple hv_WindowHandle);
// Chapter: Graphics / Output
// Short Description: Display a matrix inside a window 
void dev_display_matrix(HTuple hv_Matrix, HTuple hv_ColumnNames, HTuple hv_RowNames,
	HTuple hv_WindowHandle, HTuple hv_GenParam);
// Chapter: Deep Learning / Evaluation
// Short Description: Display the confusion matrix given by ConfusionMatrix. 
void dev_display_pixel_confusion_matrix(HTuple hv_ConfusionMatrix, HTuple hv_ClassNames,
	HTuple hv_GenParam, HTuple hv_WindowHandles);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Display the detected anomaly regions. 
void dev_display_result_anomaly_regions(HObject ho_AnomalyImage, HObject *ho_AnomalyRegion,
	HTuple hv_CurrentWindowHandle, HTuple hv_AnomalyRegionThreshold, HTuple hv_LineWidth,
	HTuple hv_AnomalyRegionResultColor);
// Chapter: Graphics / Output
// Short Description: Display result bounding boxes. 
void dev_display_result_detection(HTuple hv_DLResult, HTuple hv_ResultKeys, HTuple hv_LineWidthBbox,
	HTuple hv_ClassIDs, HTuple hv_TextConf, HTuple hv_Colors, HTuple hv_BoxLabelColor,
	HTuple hv_WindowImageRatio, HTuple hv_TextPositionRow, HTuple hv_TextColor, HTuple hv_ShowLabels,
	HTuple hv_ShowDirection, HTuple hv_WindowHandle, HTuple *hv_BboxIDs);
// Chapter: Deep Learning / Evaluation
// Short Description: Visualize the results of an evaluation for a model of type segmentation. 
void dev_display_segmentation_evaluation(HTuple hv_EvaluationResult, HTuple hv_EvalParam,
	HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// Chapter: Graphics / Output
// Short Description: Display the ground truth/result segmentation as regions. 
void dev_display_segmentation_regions(HObject ho_SegmentationImage, HTuple hv_ClassIDs,
	HTuple hv_ColorsSegmentation, HTuple hv_ExcludeClassIDs, HTuple *hv_ImageClassIDs);
// Chapter: Graphics / Output
// Short Description: Display a map of weights. 
void dev_display_weight_regions(HObject ho_ImageWeight, HTuple hv_DrawTransparency,
	HTuple hv_SegMaxWeight, HTuple *hv_Colors);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Get the ground truth anomaly label and label ID. 
void get_anomaly_ground_truth_label(HTuple hv_SampleKeys, HTuple hv_DLSample, HTuple *hv_AnomalyLabelGroundTruth,
	HTuple *hv_AnomalyLabelIDGroundTruth);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Get the anomaly image out of DLResult. 
void get_anomaly_result(HObject *ho_AnomalyImage, HTuple hv_ResultKeys, HTuple hv_DLResult,
	HTuple *hv_AnomalyScore, HTuple *hv_AnomalyClassID);
// Chapter: Graphics / Window
// Short Description: Get the next child window that can be used for visualization. 
void get_child_window(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
	HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Deep Learning / Classification
// Short Description: Get the ground truth classification label id. 
void get_classification_ground_truth(HTuple hv_SampleKeys, HTuple hv_DLSample, HTuple *hv_ClassificationLabelIDGroundTruth);
// Chapter: Deep Learning / Classification
// Short Description: Get the predicted classification class ID. 
void get_classification_result(HTuple hv_ResultKeys, HTuple hv_DLResult, HTuple *hv_ClassificationClassID);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the confidences of the segmentation result. 
void get_confidence_image(HObject *ho_ImageConfidence, HTuple hv_ResultKeys, HTuple hv_DLResult);
// Chapter: Deep Learning / Model
// Short Description: Generate NumColors distinct colors 
void get_distinct_colors(HTuple hv_NumColors, HTuple hv_Random, HTuple hv_StartColor,
	HTuple hv_EndColor, HTuple *hv_Colors);
// Chapter: Deep Learning / Model
// Short Description: Generates certain colors for different ClassNames 
void get_dl_class_colors(HTuple hv_ClassNames, HTuple *hv_Colors);
// Chapter: Deep Learning / Model
// Short Description: Get the image of a sample. 
void get_image(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// Chapter: Graphics / Window
// Short Description: Get the next window that can be used for visualization. 
void get_next_window(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
	HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
	HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
	HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the ground truth segmentation image. 
void get_segmentation_image_ground_truth(HObject *ho_SegmentationImagGroundTruth,
	HTuple hv_SampleKeys, HTuple hv_DLSample);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the predicted segmentation result image. 
void get_segmentation_image_result(HObject *ho_SegmentationImageResult, HTuple hv_ResultKeys,
	HTuple hv_DLResult);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the weight image of a sample. 
void get_weight_image(HObject *ho_ImageWeight, HTuple hv_SampleKeys, HTuple hv_DLSample);
// Chapter: Deep Learning / Model
// Short Description: shuffles the input colors in a deterministic way 
void make_neighboring_colors_distinguishable(HTuple hv_ColorsRainbow, HTuple *hv_Colors);
// Chapter: Graphics / Window
// Short Description: Open a window next to the given WindowHandleFather.  
void open_child_window(HTuple hv_WindowHandleFather, HTuple hv_Font, HTuple hv_FontSize,
	HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_WindowHandleChild, HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Graphics / Window
// Short Description: Open a new window, either next to the last ones, or in a new row. 
void open_next_window(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
	HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
	HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_WindowHandleNew, HTuple *hv_WindowImageRatioHeight,
	HTuple *hv_PrevWindowCoordinatesOut);

// Chapter: Graphics / Window
// Short Description: This procedure sets and returns meta information to display images correctly. 
void update_window_meta_information(HTuple hv_WindowHandle, HTuple hv_WidthImage,
	HTuple hv_HeightImage, HTuple hv_WindowRow1, HTuple hv_WindowColumn1, HTuple hv_MapColorBarWidth,
	HTuple hv_MarginBottom, HTuple *hv_WindowImageRatioHeight, HTuple *hv_WindowImageRatioWidth,
	HTuple *hv_SetPartRow2, HTuple *hv_SetPartColumn2, HTuple *hv_PrevWindowCoordinatesOut);


#endif //