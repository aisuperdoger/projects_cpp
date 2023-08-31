// Code generated by protoc-gen-go.
// source: examples/sudoku/sudoku.proto
// DO NOT EDIT!

/*
Package sudoku is a generated protocol buffer package.

It is generated from these files:
	examples/sudoku/sudoku.proto

It has these top-level messages:
	SudokuRequest
	SudokuResponse
*/
package sudoku

import proto "code.google.com/p/goprotobuf/proto"
import json "encoding/json"
import math "math"

// RPC Imports
import "io"
import "net/rpc"
import "github.com/chenshuo/muduo-protorpc/go/muduorpc"

// Reference proto, json, and math imports to suppress error if they are not otherwise used.
var _ = proto.Marshal
var _ = &json.SyntaxError{}
var _ = math.Inf

type SudokuRequest struct {
	Checkerboard     *string `protobuf:"bytes,1,req,name=checkerboard" json:"checkerboard,omitempty"`
	XXX_unrecognized []byte  `json:"-"`
}

func (m *SudokuRequest) Reset()         { *m = SudokuRequest{} }
func (m *SudokuRequest) String() string { return proto.CompactTextString(m) }
func (*SudokuRequest) ProtoMessage()    {}

func (m *SudokuRequest) GetCheckerboard() string {
	if m != nil && m.Checkerboard != nil {
		return *m.Checkerboard
	}
	return ""
}

type SudokuResponse struct {
	Solved           *bool   `protobuf:"varint,1,opt,name=solved,def=0" json:"solved,omitempty"`
	Checkerboard     *string `protobuf:"bytes,2,opt,name=checkerboard" json:"checkerboard,omitempty"`
	XXX_unrecognized []byte  `json:"-"`
}

func (m *SudokuResponse) Reset()         { *m = SudokuResponse{} }
func (m *SudokuResponse) String() string { return proto.CompactTextString(m) }
func (*SudokuResponse) ProtoMessage()    {}

const Default_SudokuResponse_Solved bool = false

func (m *SudokuResponse) GetSolved() bool {
	if m != nil && m.Solved != nil {
		return *m.Solved
	}
	return Default_SudokuResponse_Solved
}

func (m *SudokuResponse) GetCheckerboard() string {
	if m != nil && m.Checkerboard != nil {
		return *m.Checkerboard
	}
	return ""
}

func init() {
}

// Services

type SudokuService interface {
	Solve(req *SudokuRequest, resp *SudokuResponse) error
}

func RegisterSudokuService(service SudokuService) {
	rpc.RegisterName("sudoku.SudokuService", service)
}

func NewSudokuServiceClient(conn io.ReadWriteCloser) *SudokuServiceClient {
	codec := muduorpc.NewClientCodec(conn)
	client := rpc.NewClientWithCodec(codec)
	return &SudokuServiceClient{client}
}

type SudokuServiceClient struct {
	client *rpc.Client
}

func (c *SudokuServiceClient) Close() error {
	return c.client.Close()
}

func (c *SudokuServiceClient) Solve(req *SudokuRequest, resp *SudokuResponse) error {
	return c.client.Call("sudoku.SudokuService.Solve", req, resp)
}