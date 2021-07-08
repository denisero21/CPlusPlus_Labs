object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 390
  ClientWidth = 792
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 12
    Width = 11
    Height = 13
    Caption = 'ID'
  end
  object Label2: TLabel
    Left = 16
    Top = 54
    Width = 33
    Height = 13
    Caption = 'Author'
  end
  object Label3: TLabel
    Left = 16
    Top = 97
    Width = 20
    Height = 13
    Caption = 'Title'
  end
  object Label4: TLabel
    Left = 16
    Top = 140
    Width = 89
    Height = 13
    Caption = 'Year of publication'
  end
  object Label5: TLabel
    Left = 16
    Top = 183
    Width = 79
    Height = 13
    Caption = 'Publishing house'
  end
  object Label6: TLabel
    Left = 16
    Top = 226
    Width = 82
    Height = 13
    Caption = 'Amount of pages'
  end
  object Label7: TLabel
    Left = 400
    Top = 16
    Width = 119
    Height = 13
    Caption = 'Enter ID to find the book'
  end
  object Label8: TLabel
    Left = 400
    Top = 94
    Width = 190
    Height = 13
    Caption = 'Enter the author to find the information'
  end
  object Label9: TLabel
    Left = 400
    Top = 180
    Width = 261
    Height = 13
    Caption = 'Enter the title  and year of publication to find the book'
  end
  object Label10: TLabel
    Left = 400
    Top = 264
    Width = 229
    Height = 13
    Caption = 'Choose ID to delete the information about book'
  end
  object Edit1: TEdit
    Left = 16
    Top = 27
    Width = 153
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 16
    Top = 70
    Width = 153
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 16
    Top = 113
    Width = 153
    Height = 21
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 16
    Top = 156
    Width = 153
    Height = 21
    TabOrder = 3
  end
  object Edit5: TEdit
    Left = 16
    Top = 199
    Width = 153
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 16
    Top = 276
    Width = 89
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 307
    Width = 89
    Height = 25
    Caption = 'Show All'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 400
    Top = 62
    Width = 89
    Height = 25
    Caption = 'Search'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 400
    Top = 140
    Width = 89
    Height = 25
    Caption = 'Search'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 400
    Top = 226
    Width = 89
    Height = 25
    Caption = 'Search'
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 16
    Top = 338
    Width = 89
    Height = 25
    Caption = 'Exit'
    TabOrder = 10
    OnClick = Button6Click
  end
  object Edit6: TEdit
    Left = 16
    Top = 243
    Width = 153
    Height = 21
    TabOrder = 11
  end
  object Memo1: TMemo
    Left = 192
    Top = 21
    Width = 185
    Height = 243
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 12
  end
  object Edit7: TEdit
    Left = 400
    Top = 35
    Width = 129
    Height = 21
    TabOrder = 13
  end
  object Edit8: TEdit
    Left = 400
    Top = 113
    Width = 129
    Height = 21
    TabOrder = 14
  end
  object Edit9: TEdit
    Left = 400
    Top = 199
    Width = 129
    Height = 21
    TabOrder = 15
  end
  object Edit10: TEdit
    Left = 532
    Top = 199
    Width = 129
    Height = 21
    TabOrder = 16
  end
  object Button7: TButton
    Left = 400
    Top = 307
    Width = 89
    Height = 25
    Caption = 'Delete'
    TabOrder = 17
    OnClick = Button7Click
  end
  object ComboBox1: TComboBox
    Left = 400
    Top = 283
    Width = 145
    Height = 21
    TabOrder = 18
  end
end
